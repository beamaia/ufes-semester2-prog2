#include <stdio.h>
#include "terreno.h"
#include "triangulo.h"

//Leitura das informacoes do terreno tipo triangulo
void le_triangulo(tTriangulo *tri, FILE *arq)
{
    le_terreno(&tri->ter, arq);
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
    return area_triangulo(tri) * fator_preco_terreno(&tri->ter);
}