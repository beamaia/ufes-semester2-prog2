#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

//Dados do terrento tipo retangulo. Lado1, lado2, tipo de solo e preco do m2
struct retangulo
{
    float lado1,
          lado2;
    char solo;
    unsigned int preco;
};

Retangulo inicializa_retangulo()
{
    Retangulo ret;
    ret = (Retangulo) malloc(sizeof(struct retangulo));

    if(ret == NULL)
    {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    
    return ret;
}

//Leitura das informacoes do terreno tipo retangulo.
void le_retangulo(Retangulo ret, FILE *arq)
{
    fscanf(arq, "%c\n", &ret->solo);
    fscanf(arq, "%u\n", &ret->preco);
    fscanf(arq, "%f\n", &ret->lado1);
    fscanf(arq, "%f\n", &ret->lado2);
}

//Calcula a area do terreno tipo retangulo.
float area_retangulo(Retangulo ret)
{
    return (float) ret->lado1 * ret->lado2;
}

//Calcula o preco do terreno tipo retangulo.
float preco_retangulo(Retangulo ret)
{
    switch (ret->solo)
    {
        case 'A': return area_retangulo(ret) * 0.9 * ((float) ret->preco);
        case 'G': return area_retangulo(ret) * 1.3 * ((float) ret->preco);
        case 'R': return area_retangulo(ret) * 1.1 * ((float) ret->preco);
        return 0;
    }
}

//Verifica se o solo do terreno tipo retangulo e argiloso.
int solo_argiloso_retangulo(Retangulo ret)
{
    if(ret->solo == 'G')
        return 1;
    
    return 0;
}   

void libera_retangulo(Retangulo ret)
{
    free(ret);
}