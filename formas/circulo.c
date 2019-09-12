#include <stdio.h> 
#include <math.h>
#include "ponto.h"
#include "circulo.h"
#define PI 3.14

void leia_circulo(tCirculo *c)
{
    printf("\nDigite o ponto de origem:\n");
    leia_ponto(&c->origem);
    printf("Digite o tamanho do raio:\n ");
    scanf("%f", &c->raio);
}

float area_circulo(tCirculo *c)
{
    return (PI * pow(c->raio,2));
}

float perimetro_circulo(tCirculo *c)
{
    return (2 * PI * (c->raio));
}

void apresenta_circulo(tCirculo *c)
{
    printf("Forma: Circular ");
    printf("Raio: %f ", c->raio);
    printf("Origem: ");
    apresenta_ponto(&c->origem);
}