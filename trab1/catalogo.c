#include <stdio.h>
#include "imovel.h"
#include "catalogo.h"
#include "espec.h"

void inicializa_catalogo(tCatalogo *c)
{
    c->qtd_imoveis = 0;
}

void le_catalogo(tCatalogo *c, FILE *arq)
{
    while(feop(arq))
    {
        c->qtd_imoveis++;
        le_imovel(c->imovel[c->qtd_imoveis - 1]);
    }
}

void altera_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            c->qtd_imoveis[i] = imo;
            break;
        }
    }
}

void inclusao_imovel(tCatalogo *c, tImovel *imo)
{
    c->qtd_imoveis[c->++qtd_imoveis] = imo;
}

void exclusao_imovel(tCatalogo *)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            c->qtd_imoveis--;
            for(int j = i; j < c->qtd_imoveis; j++)
            {
                c->imoveis[j] = c->imoveis[j + 1];
            }
            break;
        }
    }    
}

void le_atual(tCatalogo *c, FILE *arq)
{
    tImovel aux;
    char acao;

    while(feop(arq))
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
            case 'e': exclusao_imovel(c, arq);            
        }
    }
}

void calcula_preco(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        preco_imovel(&c->imoveis[i]);
    }
}

void ordena(tCatalogo *c, int (* cmp)(tImovel *, tImovel *))
{
    tImovel aux;
    for(int i = 0; i < c->qtd_imoveis - 1; i++)
    {
        for(int j = 0; j < c->qtd_imoveis - i - 1; j++)
        {
            if((*cmp)(&c->imoveis[j], &c->imoveis[j+1]))
            {
                aux = c->imoveis[j];
                c->qtd_imoveis[j] = c->qtd_imoveis[j + 1];
                c->qtd_imoveis[j + 1] = aux;
            }
        }
    }
}

int calcula_qtd_caros(tCatalogo *c1, tEspec *espec)
{
    return espec->pecent_caros * c1->qtd_imoveis / 100;
}

void imoveis_mais_caros(tCatalogo *c, tEspec *espec, tIdentificadores *id)
{
    ordena(c, compara_preco);
    if(espec->i > c->qtd_imoveis || espec->i == 0)
    {
        id->i = 0;
    }
    else
    {
        id->i = c->imoveis[espec->i - 1];
    }
}

int calcula_qtd_argilosos(tCatalogo *c, tEspec *espec)
{
    return espec->percent_argiloso * c->qtd_imoveis;
}

void catalogo_argiloso(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    for(int i = 0, j = 0; i < c1->qtd_imoveis; i++)
    {
        for(; j < c1->qtd_imoveis; j++)
        {
            if(imovel_identifica_argiloso(&c1->imoveis))
            {
                c2->imoveis[i] = c1->imoveis[j];
                break;
            }
        }

        if(j == c1->qtd_imoveis)
        {
            c2->qtd_imoveis = i;
            break;
        }
    }
}

void terrenos_argilosos_menores(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_argiloso(c1, c2, espec);
    ordena(c2, compara_area);

    if(espec->j > c->qtd_imoveis || espec->j == 0)
    {
        id->j = 0;
    }
    else
    {
        id->j = c->imoveis[espec->j - 1];
    }

}

void catalogo_casas(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    for(int i = 0, j = 0; i < c1->qtd_imoveis; i++)
    {
        for(; j < c1->qtd_imoveis; j++)
        {
            if(imovel_limite_area_preco(&c1->qtd_imoveis[j], &espec))
            {
                c2->imoveis[i] = c1->imoveis[j];
                break;
            }
        }

        if(j == c1->qtd_imoveis)
        {
            c2->qtd_imoveis = i;
            break;
        }
    }
}

void casas_limite(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_casas(c1, c2, espec);
    ordena(c2, compara_quartos);
    
    if(espec->k > c->qtd_imoveis || espec->k == 0)
    {
        id->k = 0;
    }
    else
    {
        id->k = c->imoveis[espec->k - 1];
    }
}

void apresenta_imoveis_caros(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificaor(c->imoveis[i]);
    }

    printf("\n")

}

void apresenta_terrenos_argilosos(tCatalogo *c, int limite)
{
    for(int i = limite; i >= 0; i--)
    {
        imovel_apresenta_identificaor(c->imoveis[i]);
    }

    printf("\n");
}

void apresenta_casas_limite(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificaor(c->imoveis[i]);
    }

    printf("\n");
}

void apresenta_catalogos(tCatalogo *c1, tCatalogo *c2, tCatalogo *c3, tIdentificadores *id)
{
    printf("%d\n", id->i + id->j + id->k);
    apresenta_imoveis_caros(c1, calcula_qtd_caros(c1, espec));
    apresenta_terrenos_argilosos(c2, calcula_qtd_argilosos(c2, espec));
    apresenta_casas_limite(c3);
}
