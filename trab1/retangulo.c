#include <stdio.h>
#include "retangulo.h"

//Leitura das informacoes do terreno tipo retangulo
void le_retangulo(tRetangulo *ret, FILE *arq)
{
    fscanf(arq, "%c%*c", &ret->solo);
    fscanf(arq, "%d%*c", &ret->preco);
    fscanf(arq, "%f%*c", &ret->lado1);
    fscanf(arq, "%f%*c", &ret->lado2);
}

//Calcula a area do terreno tipo retangulo
float area_retagulo(tRetangulo *ret)
{
    return ret->lado1 * ret->lado2;
}

//Calcula o preco do terreno tipo retangulo
float preco_retangulo(tRetangulo *ret)
{
    float fator;
    switch (ret->solo)
    {
        case 'A': fator =  0.9 * ret->preco;
        case 'G': fator =  1.3 * ret->preco;
        case 'R': fator = 1.1 * ret->preco;
    }
    return area_retagulo(ret) * fator;
}

//Verifica se o solo do terreno tipo retangulo e argiloso
int solo_argiloso_retangulo(tRetangulo *ret)
{
    if(ret->solo == 'A')
        return 1;
    
    return 0;
}   