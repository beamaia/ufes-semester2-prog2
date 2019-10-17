#include <stdio.h>
#include "retangulo.h"

//Leitura das informacoes de terreno formato retangular
void le_retangulo(tRetangulo *r, FILE *fp)
{
    fscanf(fp, "%c%*c%f%*c%f%*c%f", &r->solo,
                                    &r->preco_m2,
                                    &r->lado1, 
                                    &r->lado2);
}

//Calcula a area do retangulo
void area_retangulo(tRetangulo *r)
{
    r->area = r->lado1 * r->lado2;
}

float preco_retangulo(tRetangulo *r)
{
    switch(r->solo)
    {
        case 'A': return r->preco_m2 * r->area * 0.9;
        case 'G': return r->preco_m2 * r->area * 1.3;
        case 'R': return r->preco_m2 * r->area * 1.1;
    }
}
