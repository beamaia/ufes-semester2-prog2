#include <stdio.h>
#include <stdlib.h>
#include "trapezio.h"

//Dados do terrento tipo trapezio. Base1, base2, altura, tipo de solo e preco do m2
struct trapezio
{
    float base1,
          base2,
          altura;
    char solo;
    unsigned int preco;
};

Trapezio inicializa_trapezio()
{
    Trapezio tra;
    tra = (Trapezio) malloc(sizeof(struct trapezio));

    if(tra == NULL)
    {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    
    return tra;
}

//Leitura das informacoes do terreno tipo trapezio.
void le_trapezio(Trapezio tra, FILE *arq)
{
    fscanf(arq, "%c\n", &tra->solo);
    fscanf(arq, "%u\n", &tra->preco);
    fscanf(arq, "%f\n", &tra->base1);
    fscanf(arq, "%f\n", &tra->base2);
    fscanf(arq, "%f\n", &tra->altura);
}

//Calcula a area do terreno tipo trapezio.
float area_trapezio(Trapezio tra)
{
    return ((tra->base1 + tra->base2) * tra->altura) / 2;
}

//Calcula o preco do terreno tipo trapezio.
float preco_trapezio(Trapezio tra)
{
    switch (tra->solo)
    {
        case 'A': return area_trapezio(tra) * 0.9 * ((float) tra->preco);
        case 'G': return area_trapezio(tra) * 1.3 * ((float) tra->preco);
        case 'R': return area_trapezio(tra) * 1.1 * ((float) tra->preco);
        default: return 0;
    }
}

//Verifica se o solo do terreno tipo trapezio e argiloso.
int solo_argiloso_trapezio(Trapezio tra)
{
    if(tra->solo == 'G')
        return 1;
    
    return 0;
}   

void libera_trapezio(Trapezio tra)
{
    free(tra);
}