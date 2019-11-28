#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espec.h"
//#include "triangulo.h"
//#include "retangulo.h"
//#include "trapezio.h"
//#include "casa.h"
//#include "apto.h"
//#include "categoria.h"
#include "imovel.h"
#include "catalogo.h"
#define MAX_IMO 20

//Dados do catalogo. Um catalogo de varios imoveis e a quantidade de imoveis nesse catalogo.
struct catalogo
{
    Imovel *imoveis;
    unsigned int qtd_imoveis,
                 qtd_max;
    
};

//Coloca 0 em quantidade de imoveis do catalogo.
Catalogo inicializa_catalogo()
{
    Catalogo c;
    c = (Catalogo) malloc(sizeof(struct catalogo));
    if(c == NULL)
    {
        printf("Erro na alocação de memoria, abortando programa");
        exit(1);
    }

    c->qtd_imoveis = 0;
    c->qtd_max = MAX_IMO;
    c->imoveis = (Imovel *) malloc(sizeof(Imovel) * c->qtd_max);

    if(c->imoveis == NULL)
    {
        printf("Erro na alocação de memoria, abortando programa");
        exit(1);
    }

    return c;
}

void expande_catalogo(Catalogo c)
{
    c->qtd_max += MAX_IMO;
    Imovel *aux = (Imovel *) malloc(sizeof(Imovel) * c->qtd_max);


    if(aux == NULL)
    {
        printf("Erro na alocação de memoria, abortando programa");
        exit(1);        
    }

    for(unsigned int i = 0; i < c->qtd_imoveis; i++)
    {
        aux[i] = inicializa_imoveis();
        modifica_imovel_inclusao(aux[i], c->imoveis[i]);
        libera_imovel(c->imoveis[i]);
    }

    c->imoveis = aux;

}

/*
Leitura dos imoveis do catalogo, sempre acrescentando 1 a quantidade de imoveis
no catalogo.
*/

void le_catalogo(Catalogo c, FILE *arq)
{
    for(int i = 0; !feof(arq) && i < c->qtd_max + 1; i++)
    {
        if(c->qtd_imoveis == c->qtd_max)
        {
            expande_catalogo(c);
        }

        c->imoveis[i] = inicializa_imoveis();
        if(le_imovel(c->imoveis[i], arq) && c->qtd_imoveis < c->qtd_max)
        {
            c->qtd_imoveis++;
        }
    }
}

//Altera um imovel no catalogo para ser igual ao imovel imo caso seus numeros de identificacao sejam iguais.
void altera_imovel(Catalogo c, Imovel imo)
{
    for(int i = 0; i < c->qtd_imoveis && i < c->qtd_max; i++)
    {
        if(compara_id(c->imoveis[i], imo))
        {
            modifica_imovel_alteracao(c->imoveis[i], imo);
            break;
        }
    }
}

/*
Inclui o imovel imo no catalogo caso o catalogo nao tenha mais que o MAX_IMO de imoveis
e aumenta a quantidade de imoveis no catalogo.
*/
void inclusao_imovel(Catalogo c, Imovel imo)
{
    if(c->qtd_imoveis == MAX_IMO)
        return;

    c->imoveis[c->qtd_imoveis] = inicializa_imoveis();
    modifica_imovel_inclusao(c->imoveis[c->qtd_imoveis], imo);
    c->qtd_imoveis++;
}

/*
Procura no catalogo um imovel com o mesmo numero de identificao que o imovel imo, e caso 
tenha, retire-o do catalogo, diminuindo a quantidade de imoveis totais.
*/
void exclusao_imovel(Catalogo c, Imovel imo)
{
    for(int i = 0; i < c->qtd_imoveis && i < c->qtd_max; i++)
    {
        if(compara_id(c->imoveis[i], imo))
        {
            for(int j = i; j < c->qtd_imoveis - 1 && i < c->qtd_max; j++)
            {
                modifica_imovel_alteracao(c->imoveis[j], c->imoveis[j + 1]);
            }

            c->qtd_imoveis--;
            break;
        }
    }    
}

/*
Leitura do arquivo atual.txt, identifica-se se um imovel deve ser alterado, incluido ou 
excluido e depois chama a funcao necessaria para tal acao.
*/
void le_atual(Catalogo c, FILE *arq)
{
    Imovel aux;
    char acao = '0';
    unsigned int temp = 0;

    while(!feof(arq))
    {
        fscanf(arq, "%c\n", &acao);

        if(c->qtd_imoveis == c->qtd_max)
        {
            expande_catalogo(c);
        }

        aux = inicializa_imoveis();

        switch(acao)
        {
            case 'a': le_imovel(aux, arq);
                      altera_imovel(c, aux);
                      break;
            case 'i': le_imovel(aux, arq);
                      inclusao_imovel(c, aux);
                      break;
            case 'e': fscanf(arq, "%u%*c", &temp);
                      acrescenta_id(aux, temp);
                      exclusao_imovel(c, aux);
                      break;
            default:  break;
        }

//        libera_imovel(aux);
    }
}

int tem_imoveis_no_catalogo(Catalogo c)
{
    return (c->qtd_imoveis > 0);
}

//Calcula o preco de todos imoveis do catalogo.
void calcula_preco(Catalogo c)
{
    for(int i = 0; i < c->qtd_imoveis && i < c->qtd_max; i++)
    {
        preco_imovel(c->imoveis[i]);
    }
}

//Calcula a area de todos imoveis do catalogo.
void calcula_area(Catalogo c)
{
    for(int i = 0; i < c->qtd_imoveis && i < c->qtd_max; i++)
    {
        area_imovel(c->imoveis[i]);
    }
}

//Ordena o catalogo com base em uma funcao que recebe (tImovel *, tImovel *) como parametro.
void ordena(Catalogo c, int (* cmp)(Imovel, Imovel))
{
    Imovel aux;
    aux = inicializa_imoveis();
    for(int i = 0; i < c->qtd_imoveis - 1 && i < c->qtd_max; i++)
    {
        for(unsigned int j = 0; j < c->qtd_imoveis - i - 1 && j < c->qtd_max; j++)
        {
            if((*cmp)(c->imoveis[j], c->imoveis[j + 1]))
            {
                modifica_imovel_inclusao(aux, c->imoveis[j]);
                modifica_imovel_inclusao(c->imoveis[j], c->imoveis[j + 1]);
                modifica_imovel_inclusao(c->imoveis[j + 1], aux);
            }
        }
    }
}

//Calcula a quantidade de imoveis que serao apresentados.
unsigned int calcula_qtd_caros(Catalogo c1, Espec espec)
{
    return calcula_qtd_cara_espec(espec, c1->qtd_imoveis);
}

//Calcula a quantidade de imoveis argilosos que serao apresentados.
unsigned int calcula_qtd_argilosos(Catalogo c, Espec espec)
{
    return calcula_qtd_argilosos_espec(espec, c->qtd_imoveis);
}


//Cria um catalogo c2 baseado nos terrenos argilosos do catalogo c1.
void catalogo_argiloso(Catalogo c1, Catalogo c2)
{
    for(int i = 0; i < c1->qtd_imoveis && i < c1->qtd_max; i++)
    {
        if(imovel_identifica_argiloso(c1->imoveis[i]))
        {
            c2->imoveis[c2->qtd_imoveis] = inicializa_imoveis();
            modifica_imovel_inclusao(c2->imoveis[c2->qtd_imoveis], c1->imoveis[i]);
            c2->qtd_imoveis++;
        }
    }
}

//Cria um catalogo c2 baseado nas casas dentro do limite das informacoes do arquivo espec.txt.
void catalogo_casas(Catalogo c1, Catalogo c2, Espec espec)
{
    for(int i = 0; i < c1->qtd_imoveis && i < c1->qtd_max; i++)
    {
        if(identifica_categoria(c1->imoveis[i]) == 4)
        {
            if(imovel_limite_area_preco(c1->imoveis[i], espec))
            {
                c2->imoveis[c2->qtd_imoveis] = inicializa_imoveis();
                modifica_imovel_inclusao(c2->imoveis[c2->qtd_imoveis], c1->imoveis[i]);
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
void imoveis_mais_caros(Catalogo c, Espec espec, Identificadores id)
{
    if(!c->qtd_imoveis)
        return;

    ordena(c, compara_preco);

    unsigned int limite = calcula_qtd_caros(c, espec);

    if(espec_id_zerado(espec, 1) || espec_id_limite(espec, 1, c->qtd_imoveis))
        zera_id(id, 1);
    else
    {
        atribui_valor_id(id, identifica_id(c->imoveis[get_espec_letra(espec, 1) - 1 + c->qtd_imoveis - limite]), 1);
    }
}

/*
Executa o item b. Cria um catalogo de imoveis argilosos, chama a funcao ordena, utilizando 
para comparacao a area. E por ultimo, armazena o numero de identificao do catalogo de imoveis
argilosos de acordo com as informacoes do arquivo espec.txt.
*/
void terrenos_argilosos_menores(Catalogo c1, Catalogo c2, Identificadores id, Espec espec)
{
    catalogo_argiloso(c1, c2);

    if(!c2->qtd_imoveis)
    {
        return;
    }

    ordena(c2, compara_area);
    unsigned int limite = calcula_qtd_argilosos(c2, espec);

    if(espec_id_zerado(espec, 2) || espec_id_limite(espec, 2, c2->qtd_imoveis))
        zera_id(id, 2);
    else
        atribui_valor_id(id, identifica_id(c2->imoveis[get_espec_letra(espec, 2) - 1 + c2->qtd_imoveis - limite]), 2);

}

/*
Executa o item c. Cria um catalogo de imoveis de casas, chama a funcao ordena, utilizando 
para comparacao a quantidade de quartos. E por ultimo, armazena o numero de identificao do 
catalogo de imoveis de casas de acordo com as informacoes do arquivo espec.txt.
*/
void casas_limite(Catalogo c1, Catalogo c2, Identificadores id, Espec espec)
{
    catalogo_casas(c1, c2, espec);

    if(!c2->qtd_imoveis)
    {
        return;
    }

    ordena(c2, compara_quartos);
    
    if(espec_id_zerado(espec, 3) || espec_id_limite(espec, 3, c2->qtd_imoveis))
        zera_id(id, 3);
    else
        atribui_valor_id(id, identifica_id(c2->imoveis[get_espec_letra(espec, 3) - 1]), 3);
}

//Apresenta o numero de identificao dos imoveis mais caros.
void apresenta_imoveis_caros(Catalogo c, int limite)
{
    for(int i = (int) c->qtd_imoveis - limite; i < c->qtd_imoveis && i >= 0 && i < c->qtd_max; i++)
    {
        imovel_apresenta_identificador(c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }
    if(c->qtd_imoveis)
        printf("\n");

}

//Apresenta o numero de identificacao dos terrenos argilosos.
void apresenta_terrenos_argilosos(Catalogo c, int limite)
{
    for(int i = (int) c->qtd_imoveis - limite; i < c->qtd_imoveis && i < c->qtd_max; i++)
    {
        imovel_apresenta_identificador(c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
        }
    if(c->qtd_imoveis)
        printf("\n");
}

//Apresenta o numero de identificacao das casas.
void apresenta_casas_limite(Catalogo c)
{
    for(int i = 0; i < c->qtd_imoveis && i < c->qtd_max; i++)
    {
        imovel_apresenta_identificador(c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    if(c->qtd_imoveis)
        printf("\n");
}

/*
Cria um arquivo saida.txt com a soma dos identificadores especificados pelo arquivo espec.txt e os numeros de 
identificacao dos imoveis mais caros, terrenos argilosos e das casas, de acordo com as informacoes do arquivo 
espec.txt
*/
void apresenta_catalogos(Catalogo c1, Catalogo c2, Catalogo c3, Identificadores id, Espec espec)
{
    imprime_soma_id(id);
    if(c1->qtd_imoveis)
    {
        apresenta_imoveis_caros(c1, (int) calcula_qtd_caros(c1, espec));
        apresenta_terrenos_argilosos(c2, (int) calcula_qtd_argilosos(c2, espec));
        apresenta_casas_limite(c3);
    }
}

void libera_catalogo(Catalogo c)
{
    for(int i = 0; i < (int) c->qtd_imoveis; i++)
    {
        libera_imovel(c->imoveis[i]);
    }

    free(c->imoveis);
    free(c);
}
void libera_apenas_catalogo(Catalogo c)
{
    free(c->imoveis);
    free(c);
}