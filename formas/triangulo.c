#include <stdio.h> 
#include <math.h>
#include "ponto.h"
#include "triangulo.h"

void leia_triangulo(tTriangulo *t)
{
    printf("\nDigite v1, v2 e v3:\n");
    leia_ponto(&t->v1);
    leia_ponto(&t->v2);
    leia_ponto(&t->v3);
    printf("Digite base e altura: \n");
    scanf("%f%f", &t->base, &t->altura);
}

float area_triangulo(tTriangulo * t)
{
    return t->base * t->altura / 2;
}

float perimetro_triangulo(tTriangulo * t)
{
    float d1, d2, d3;
    d1 = distancia(&t->v1, &t->v2);
    d2 = distancia(&t->v2, &t->v3);
    d3 = distancia(&t->v1, &t->v3);

    return d1 + d2 + d3;
}

void apresenta_triangulo(tTriangulo *t)
{
    printf("Forma: Triangular ");
    printf("V1: ");
    apresenta_ponto(&t->v1);
    printf("V2: ");
    apresenta_ponto(&t->v2);
    printf("V3: ");
    apresenta_ponto(&t->v3);
}