#include <stdio.h>
#include "pais.h"

void incializa_pais(tPais *p, int codigo)
{
    p->codigo = codigo;
    p->ouro = p->prata = p->bronze = 0;
}

void apresenta_pais(tPais * p)
{
    printf("%d %d %d %d\n", p->codigo,
                            p->ouro,
                            p->prata,
                            p->bronze);
}

int compara_pais(tPais *p1, tPais *p2)
{
    if(p1->ouro < p2->ouro)
        return 1;
    if(p1->prata < p2->prata)
        return 1;
    if(p1->bronze < p2->bronze)
        return 1;
    if(p1->ouro == p2->ouro && p1->prata == p2->prata && p1->bronze == p2->bronze)
       return p1->codigo > p2->codigo;
    return 0;
}

int codigo_igual(tPais *p1, tPais *p2)
{
    return p1->codigo == p2->codigo;
}

void adiciona_medalha(tPais *p, int tipo)
{
    switch(tipo)
    {
        case 0: p->ouro++;
                break;
        case 1: p->prata++;
                break;
        case 2: p->bronze++
                break;
    }
}

void adiciona_medalhas(tPais *pais, int o, int p, int b)
{
    pais->ouro += o;
    pais->prata += p;
    pais->bronze += b;
}

