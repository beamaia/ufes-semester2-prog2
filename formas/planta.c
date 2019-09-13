#include <stdio.h> 
#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"
#include "comodo.h"
#include "planta.h"

void leia_planta(tPlant * p)
{
    char tag;
    int i;
    tag = leia_tag(&p->comodo[0]);

    for(i = 0; i < 100 && tag != '0'; i++)
    {
        leia_comodo(&p->comodo[i].forma, p->comodo->tag);
        area_perimetro(&p->comodo[i]);

        if(i + 1 < 100)
        {
            tag = leia_tag(&p->comodo[i +1]);
        }
    }

    p->qtd_comodos = i;
}

void apresenta_planta(tPlant * p)
{
    char tag;
    tag = leia_tag(&p->comodo[0]);

    for(int i = 0; i < 100 && tag != '0'; i++)
    {
        apresenta_comodo(&p->comodo[i]);
        if(i + 1 < 100)
        {
            tag = leia_tag(&p->comodo[i +1]);
        }
    }    
}

void ordena(tPlant * p,  int(*compara)(tComodo *, tComodo *))
{
    tComodo aux;

    for(int i = 0; i < p->qtd_comodos - 1; i++)
        for(int j = 0; j < p->qtd_comodos - 1 - i; j++) 
            if((*compara)(&p->comodo[j], &p->comodo[j + 1]))
            {
                aux = p->comodo[j];
                p->comodo[j + 1] = p->comodo[j];
                p->comodo[j] = aux; 
            }
}   