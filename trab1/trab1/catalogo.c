#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "imovel.h"
#include "catalogo.h"
#include "espec.h"

//Coloca 0 em quantidade de imoveis do catalogo.
void inicializa_catalogo(tCatalogo *c)
{
    c->qtd_imoveis = 0;
}

/*
Leitura dos imoveis do catalogo, sempre acrescentando 1 a quantidade de imoveis
no catalogo.
*/
void le_catalogo(tCatalogo *c, FILE *arq)
{
    while(!feof(arq) && c->qtd_imoveis < (MAX_IMO + 1))
    {
        if(le_imovel(&c->imoveis[c->qtd_imoveis], arq))
        {
            c->qtd_imoveis++;
        }

        fscanf(arq, "\n");
    }
}

//Altera um imovel no catalogo para ser igual ao imovel imo caso seus numeros de identificacao sejam iguais.
void alteracao_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            modifica_imovel(&c->imoveis[i], imo);
            break;
        }
    }
}

/*
Inclui o imovel imo no catalogo caso o catalogo nao tenha mais que o MAX_IMO de imoveis
e aumenta a quantidade de imoveis no catalogo.
*/
void inclusao_imovel(tCatalogo *c, tImovel *imo)
{
    if(c->qtd_imoveis == MAX_IMO)
        return;

    c->imoveis[c->qtd_imoveis] = *imo;
    c->qtd_imoveis++;
}

/*
Procura no catalogo um imovel com o mesmo numero de identificao que o imovel imo, e caso 
tenha, retire-o do catalogo, diminuindo a quantidade de imoveis totais.
*/
void exclusao_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            c->qtd_imoveis--;
            for(int j = i; j < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); j++)
            {
                modifica_imovel(&c->imoveis[j], &c->imoveis[j + 1]);
            }
            break;
        }
    }    
}

/*
Leitura do arquivo atual.txt, identifica-se se um imovel deve ser alterado, incluido ou 
excluido e depois chama a funcao necessaria para tal acao.
*/
void le_atual(tCatalogo *c, FILE *arq)
{
    tImovel aux;
    char acao;
    int temp;

    while(!feof(arq) && (c->qtd_imoveis < (MAX_IMO + 1)))
    {
        fscanf(arq, "%c%*c", &acao);
        switch(acao)
        {
            case 'a': le_imovel(&aux, arq);
                      alteracao_imovel(c, &aux);
                      break;
            case 'i': le_imovel(&aux, arq);
                      inclusao_imovel(c, &aux);
                      break;
            case 'e': fscanf(arq, "%d%*c", &temp);
                      acrescenta_id(&aux, temp);  
                      exclusao_imovel(c, &aux);            
        }
        fscanf(arq, "%*c");
    }
}

//Calcula o preco de todos imoveis do catalogo.
void calcula_preco(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        preco_imovel(&c->imoveis[i]);
    }
}

//Calcula a area de todos imoveis do catalogo.
void calcula_area(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        area_imovel(&c->imoveis[i]);
    }
}

//Ordena o catalogo com base em uma funcao que recebe (tImovel *, tImovel *) como parametro.
void ordena(tCatalogo *c, int (* cmp)(tImovel *, tImovel *))
{
    tImovel aux;
    for(int i = 0; i < c->qtd_imoveis - 1 && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        for(int j = 0; j < c->qtd_imoveis - i - 1; j++)
        {
            if((*cmp)(&c->imoveis[j], &c->imoveis[j + 1]))
            {
                modifica_imovel(&aux, &c->imoveis[j]);
                modifica_imovel(&c->imoveis[j], &c->imoveis[j + 1]);
                modifica_imovel(&c->imoveis[j + 1], &aux);
            }
        }
    }
}

//Calcula a quantidade de imoveis que serao apresentados.
int calcula_qtd_caros(tCatalogo *c1, tEspec *espec)
{
    return espec->percent_caros * c1->qtd_imoveis / 100;
}

//Calcula a quantidade de imoveis argilosos que serao apresentados.
int calcula_qtd_argilosos(tCatalogo *c, tEspec *espec)
{
    return espec->percent_argiloso * c->qtd_imoveis / 100;
}


//Cria um catalogo c2 baseado nos terrenos argilosos do catalogo c1.
void catalogo_argiloso(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    inicializa_catalogo(c2);
    for(int i = 0; i < c1->qtd_imoveis && c1->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(imovel_identifica_argiloso(&c1->imoveis[i]))
        {
            modifica_imovel(&c2->imoveis[c2->qtd_imoveis], &c1->imoveis[i]);
            c2->qtd_imoveis++;
        }
    }
}

//Cria um catalogo c2 baseado nas casas dentro do limite das informacoes do arquivo espec.txt.
void catalogo_casas(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    inicializa_catalogo(c2);
    for(int i = 0; i < c1->qtd_imoveis && c1->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(identifica_categoria(&c1->imoveis[i]) == 4)
        {
            if(imovel_limite_area_preco(&c1->imoveis[i], espec))
            {
                modifica_imovel(&c2->imoveis[c2->qtd_imoveis], &c1->imoveis[i]);
                c2->qtd_imoveis++;
            }
        }       
    }
}

/*
Executa o item a. Chama a funcao ordena, utilizando para comparacao o preco. E por ultimo,
armazena o numero de identificao do catalogo de acordo com as informacoes do arquivo 
espec.txt.
*/ 
void imoveis_mais_caros(tCatalogo *c, tEspec *espec, tIdentificadores *id)
{
    if(!c->qtd_imoveis)
    {
        return;
    }

    ordena(c, compara_preco);

    int limite = calcula_qtd_caros(c, espec);

    if(espec->i > c->qtd_imoveis || espec->i == 0)
    {
        id->i = 0;
    }
    else
    {
        id->i = identifica_id(&c->imoveis[espec->i - 1 + c->qtd_imoveis - limite]);
    }
}

/*
Executa o item b. Cria um catalogo de imoveis argilosos, chama a funcao ordena, utilizando 
para comparacao a area. E por ultimo, armazena o numero de identificao do catalogo de imoveis
argilosos de acordo com as informacoes do arquivo espec.txt.
*/
void terrenos_argilosos_menores(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_argiloso(c1, c2, espec);

    if(!c2->qtd_imoveis)
    {
        return;
    }

    ordena(c2, compara_area);
    int limite = calcula_qtd_argilosos(c2, espec);

    if(espec->j > c2->qtd_imoveis || espec->j == 0)
    {
        id->j = 0;
    }
    else
    {
        id->j = identifica_id(&c2->imoveis[espec->j - 1 + c2->qtd_imoveis - limite]);
    }

}

/*
Executa o item c. Cria um catalogo de imoveis de casas, chama a funcao ordena, utilizando 
para comparacao a quantidade de quartos. E por ultimo, armazena o numero de identificao do 
catalogo de imoveis de casas de acordo com as informacoes do arquivo espec.txt.
*/
void casas_limite(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_casas(c1, c2, espec);

    if(!c2->qtd_imoveis)
    {
        return;
    }

    ordena(c2, compara_quartos);
    
    if(espec->k > c2->qtd_imoveis || espec->k == 0)
    {
        id->k = 0;
    }
    else
    {
        id->k = identifica_id(&c2->imoveis[espec->k - 1]);
    }
}

//Apresenta o numero de identificao dos imoveis mais caros.
void apresenta_imoveis_caros(tCatalogo *c, int limite, FILE *arq)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i], arq);
        if(i != c->qtd_imoveis - 1)
        {
            fprintf(arq, ", ");
        }
    }
    if(c->qtd_imoveis)
        fprintf(arq, "\n");

}

//Apresenta o numero de identificacao dos terrenos argilosos.
void apresenta_terrenos_argilosos(tCatalogo *c, int limite, FILE *arq)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i], arq);
        if(i != c->qtd_imoveis - 1)
        {
            fprintf(arq, ", ");
        }
        }
    if(c->qtd_imoveis)
        fprintf(arq, "\n");
}

//Apresenta o numero de identificacao das casas.
void apresenta_casas_limite(tCatalogo *c, FILE *arq)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i], arq);
        if(i != c->qtd_imoveis - 1)
        {
            fprintf(arq, ", ");
        }
    }
    if(c->qtd_imoveis)
     fprintf(arq, "\n");
}

/*
Cria um arquivo saida.txt com a soma dos identificadores especificados pelo arquivo espec.txt e os numeros de 
identificacao dos imoveis mais caros, terrenos argilosos e das casas, de acordo com as informacoes do arquivo 
espec.txt
*/
void apresenta_catalogos(tCatalogo *c1, tCatalogo *c2, tCatalogo *c3, tIdentificadores *id, tEspec *espec)
{
    FILE * arq_saida = fopen("saida.txt", "w");

    if(arq_saida == NULL)
    {
        printf("Arquivo saida.txt não criado.\n");
        exit(1);    
    }

    fprintf(arq_saida, "%d\n", id->i + id->j + id->k);
    apresenta_imoveis_caros(c1, calcula_qtd_caros(c1, espec), arq_saida);
    apresenta_terrenos_argilosos(c2, calcula_qtd_argilosos(c2, espec), arq_saida);
    apresenta_casas_limite(c3, arq_saida);

    fclose(arq_saida);
}