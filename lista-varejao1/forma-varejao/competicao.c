#include <stdio.h>
#include <stdlib.h>
#include "pais.h"
#include "competicao.h"

void inicializa_competicao(tCompeticao *c)
{
    c->paises = (tPais *)(malloc(sizeof(tPais) * EXP_COMP));
    if(!c->paises)
    {
        printf("Nao tem memória\n");
        exit(1);
    }
    c->qtd_paises = 0;
    c->max_paises = EXP_COMP;
}

void aumeta_competicao(tCompeticao * c)
{
    tPais *aux = c->paises;
    c->paises = (tPais *) malloc(sizeof(tPais)*(c->max_paises + EXP_COMP));
    if(!c->paises)
    {
        printf("Não tem memória\n");
        exit(1);
    }
    for(int i = 0; i < c->qtd_paises; i++)
    {
        c->paises[i] = aux[i];
    }
    c->max_paises += EXP_COMP;
    free(aux);
}

void atualiza_competicao(tCompeticao *c, tPais *p)
{
    for(int i = 0; i < c->qtd_paises; i++)
    {
        if(c->paises[i].codigo == p->codigo)
        {
            adiciona_medalhas(&c->paises[i], p->ouro, p->prata, p->bronze);
            return;
        }
    }
}

void apresenta_competicao(tCompeticao *c)
{
    for(int i = 0; i < c->qtd_paises; i++)
    {
        apresenta_pais(&c->paises[i]);
    }
}

void ordena_competicao(tCompeticao *c, int (*cmp)(tPais *, tPais *))
{
    tPais aux;
    for(int i = 0; i < c->qtd_paises - 1; i++)
    {
        for(int j = 0; j < c->qtd_paises - i - 1; j++)
        {
            if((*cmp)(&c->paises[j], &c->paises[j + 1]))
            {
                aux = c->paises[j];
                c->paises[j] = c->paises[j + 1];
                c->paises[j + 1] = aux;
            }
        }
    }
}

void libera_competicao(tCompeticao *c)
{
    free(c);
}