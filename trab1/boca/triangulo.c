#include <stdio.h>
#include "triangulo.h"

//Leitura das informacoes do terreno tipo triangulo.
void le_triangulo(tTriangulo *tri, FILE *arq)
{
    fscanf(arq, "%c\n", &tri->solo);
    fscanf(arq, "%d\n", &tri->preco);
    fscanf(arq, "%f\n", &tri->base);
    fscanf(arq, "%f\n", &tri->altura);
}

//Calcula a area do terreno tipo triangulo.
float area_triangulo(tTriangulo *tri)
{
    return (tri->base * tri->altura / 2.0);
}

//Calcula o preco do terreno tipo triangulo.
float preco_triangulo(tTriangulo *tri)
{
    float fator;
    switch (tri->solo)
    {
        case 'A': fator =  0.9 * ((float) tri->preco);
                  break;
        case 'G': fator =  1.3 * ((float) tri->preco);
                  break;
        case 'R': fator = 1.1 * ((float) tri->preco);
    }

    return area_triangulo(tri) * fator;
}

//Verifica se o solo do terreno tipo triangulo e argiloso
int solo_argiloso_triangulo(tTriangulo *tri)
{
    if(tri->solo == 'G')
    {
        return 1;
    }
    
    return 0;
}   
