#include <stdio.h> 
#include <math.h>
#include "ponto.h"
#include "circulo.h"

void leia_circulo(tCirculo *c)
{
    printf("\nDigite o ponto de origem:\n");
    leia_ponto(&c->origem);
    printf("Digite o tamanho do raio:\n ");
    scanf("%d", &c->raio);
}

int area_circulo(tCirculo *c)
{
    return M_PI * pow(c->raio,2);
}

int perimetro_circulo(tCirculo *c)
{
    return 2 * M_PI * c->raio;
}

void apresenta_circulo(tCirculo *c)
{
    printf("Forma: Circular ");
    printf("Raio: %d ", c->raio);
    printf("Origem: ");
    apresenta_ponto(&c->origem);
}