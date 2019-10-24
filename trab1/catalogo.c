#include <stdio.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "imovel.h"
#include "catalogo.h"
#include "espec.h"

void inicializa_catalogo(tCatalogo *c)
{
    c->qtd_imoveis = 0;
}

void le_catalogo(tCatalogo *c, FILE *arq)
{
    while(!feof(arq) && c->qtd_imoveis < 301)
    {
        c->qtd_imoveis++;
        le_imovel(&c->imoveis[c->qtd_imoveis - 1], arq);
        fscanf(arq, "\n");

    }
}

void altera_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            modifica_imovel(&c->imoveis[i], imo);
            break;
        }
    }
}

void inclusao_imovel(tCatalogo *c, tImovel *imo)
{
    if(c->qtd_imoveis == 300)
        return;

    c->imoveis[c->qtd_imoveis] = *imo;
    c->qtd_imoveis++;
}

void exclusao_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            c->qtd_imoveis--;
            for(int j = i; j < c->qtd_imoveis; j++)
            {
                modifica_imovel(&c->imoveis[j], &c->imoveis[j + 1]);
            }
            break;
        }
    }    
}

void le_atual(tCatalogo *c, FILE *arq)
{
    tImovel aux;
    char acao;
    int temp;

    while(!feof(arq) && (c->qtd_imoveis < 301))
    {
        fscanf(arq, "%c%*c", &acao);
        switch(acao)
        {
            case 'a': le_imovel(&aux, arq);
                      altera_imovel(c, &aux);
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

void calcula_preco(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        preco_imovel(&c->imoveis[i]);
    }
}

void calcula_area(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        area_imovel(&c->imoveis[i]);
    }
}

void ordena(tCatalogo *c, int (* cmp)(tImovel *, tImovel *))
{
    tImovel aux;
    for(int i = 0; i < c->qtd_imoveis - 1; i++)
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

int calcula_qtd_caros(tCatalogo *c1, tEspec *espec)
{
    return espec->percent_caros * c1->qtd_imoveis / 100;
}

void imoveis_mais_caros(tCatalogo *c, tEspec *espec, tIdentificadores *id)
{
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

int calcula_qtd_argilosos(tCatalogo *c, tEspec *espec)
{
    return espec->percent_argiloso * c->qtd_imoveis / 100;
}

void catalogo_argiloso(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    inicializa_catalogo(c2);
    for(int i = 0; i < c1->qtd_imoveis; i++)
    {
        if(imovel_identifica_argiloso(&c1->imoveis[i]))
        {
            modifica_imovel(&c2->imoveis[c2->qtd_imoveis], &c1->imoveis[i]);
            c2->qtd_imoveis++;
        }
    }
}

void terrenos_argilosos_menores(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_argiloso(c1, c2, espec);
    ordena(c2, compara_area);

    if(espec->j > c2->qtd_imoveis || espec->j == 0)
    {
        id->j = 0;
    }
    else
    {
        id->j = identifica_id(&c2->imoveis[espec->j - 1]);
    }

}

void catalogo_casas(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    inicializa_catalogo(c2);
    for(int i = 0; i < c1->qtd_imoveis; i++)
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

void casas_limite(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_casas(c1, c2, espec);
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

void apresenta_imoveis_caros(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    printf("\n");

}

void apresenta_terrenos_argilosos(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

void apresenta_casas_limite(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

void apresenta_catalogos(tCatalogo *c1, tCatalogo *c2, tCatalogo *c3, tIdentificadores *id, tEspec *espec)
{
    printf("%d\n", id->i + id->j + id->k);
    apresenta_imoveis_caros(c1, calcula_qtd_caros(c1, espec));
    apresenta_terrenos_argilosos(c2, calcula_qtd_argilosos(c2, espec));
    apresenta_casas_limite(c3);
}