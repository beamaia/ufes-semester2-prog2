#include <stdio.h>
#include "triangulo.h"
#include "terreno.h"

//Leitura das informacoes de terreno formato triangular
void le_triangulo(tTriangulo *t, FILE *fp)
{
    le_terreno(&t->terreno, fp);
    fscanf(fp, "%f%*c%f", &t->base, 
                              &t->altura);
}

//Calcula a area do triangulo
void area_triangulo(tTriangulo *t)
{
    t->area = (t->base * t->altura) / 2;
}

//Calcula o preco do terreno triangular
float preco_triangulo(tTriangulo *t)
{
    switch(t->solo)
    {
        case 'A': return t->preco_m2 * t->area * 0.9;
        case 'G': return t->preco_m2 * t->area * 1.3;
        case 'R': return t->preco_m2 * t->area * 1.1;
    }
}