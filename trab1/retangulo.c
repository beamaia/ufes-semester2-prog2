#include <stdio.h>
#include "terreno.h"
#include "retangulo.h"

//Leitura das informacoes do terreno tipo retangulo
void le_retangulo(tRetangulo *ret, FILE *arq)
{
    le_terreno(&ret->ter, arq);
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

int solo_argiloso_retangulo(tRetangulo *ret)
{
    if(ret->solo == 'A')
        return 1;
    
    return 0;
}   