#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"

//Dados do terrento tipo triangulo. Base, altura, tipo de solo e preco do m2
struct triangulo
{
    float base,
          altura;
    char solo;
    unsigned int preco;
};

Triangulo inicializa_triangulo()
{
    Triangulo tri;
    tri = (Triangulo) malloc(sizeof(struct triangulo));

    if(tri == NULL)
    {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    return tri;
}

//Leitura das informacoes do terreno tipo triangulo.
void le_triangulo(Triangulo tri, FILE *arq)
{
    fscanf(arq, "%c\n", &tri->solo);
    fscanf(arq, "%u\n", &tri->preco);
    fscanf(arq, "%f\n", &tri->base);
    fscanf(arq, "%f\n", &tri->altura);
}

//Calcula a area do terreno tipo triangulo.
float area_triangulo(Triangulo tri)
{
    return (float) (tri->base * tri->altura / 2);
}

//Calcula o preco do terreno tipo triangulo.
float preco_triangulo(Triangulo tri)
{
    switch (tri->solo)
    {
        case 'A': return (float) (area_triangulo(tri) *  0.9 * tri->preco);
        case 'G': return (float) (area_triangulo(tri) *  1.3 * tri->preco);
        case 'R': return (float) (area_triangulo(tri) * 1.1 * tri->preco);
        default: return 0;
    }
}

//Verifica se o solo do terreno tipo triangulo e argiloso
int solo_argiloso_triangulo(Triangulo tri)
{
    if(tri->solo == 'G')
        return 1;

    return 0;
}   

void libera_triangulo(Triangulo tri)
{
    free(tri);
}
