#include <stdio.h>
#include "casa.h"

//Leitura dos dados refente a  residencia tipo casa
void le_casa(tCasa *c, FILE *fp)
{
    fscanf(fp, "%d %f %d %f %d", &c->num_pav,
                                 &c->area_pav,
                                 &c->preco_pav,
                                 &c->area_livre,
                                 &c->preco_livre),
}

//Calcula o preco da casa de acordo com seus dados
int calcula_preco_casa(tCasa *c)
{
    return c->preco_pav * c->area_pav * c->num_pav + c->preco_livre * c->area_livre;
}

int compara_area_casa(tCasa *c1, tCasa *c2)
{
    if(c1->area_pav > c2->area_pav)
        return 1;

    if(c1->area_pav == c2->area_pav)
        return 2;    
        
    return 0;
}