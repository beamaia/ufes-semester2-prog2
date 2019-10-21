#include <stdio.h>
#include "terreno.h"
#include "triangulo.h"

//Leitura das informacoes do terreno tipo triangulo
void le_triangulo(tTriangulo *tri, FILE *arq)
{
    fscanf(arq, "%c%*c", &tri->solo);
    fscanf(arq, "%d%*c", &tri->preco);
    fscanf(arq, "%f%*c", &tri->base);
    fscanf(arq, "%f%*c", &tri->altura);
}

//Calcula a area do terreno tipo triangulo
float area_triangulo(tTriangulo *tri)
{
    tri->base * tri->altura / 2;
}

//Calcula o preco do terreno tipo triangulo
float preco_triangulo(tTriangulo *tri)
{
    float fator;
    switch (tri->solo)
    {
        case 'A': fator =  0.9 * tri->preco;
        case 'G': fator =  1.3 * tri->preco;
        case 'R': fator = 1.1 * tri->preco;
    }

    return area_triangulo(tri) * fator;
}

int solo_argiloso_triangulo(tTriangulo *tri)
{
    if(tri->solo == 'A')
        return 1;
    
    return 0;
}   