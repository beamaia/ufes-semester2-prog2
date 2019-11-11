#include <stdlib.h>
#include <stdio.h>
#include "espec.h"

/*
Informacoes do arquivo espec.txt como a porcentagem de imoveis caros da lista a,
a porcentagem de terrenos argilosos da lista b e a área e o preço limite das casas
que irão compor a lista c, além da posicao dos identificadores que devem ser somados 
(i, j, k) no final do programa.
*/
struct espec
{
    unsigned int percent_caros,
                 percent_argiloso,
                 i,
                 j,
                 k;
    float area_limite,
          preco_limite;
};

void inicializa_espec(Espec esp)
{
    esp->percent_caros = 0;
    esp->percent_argiloso = 0;
    esp->i = 0;
    esp->j = 0;
    esp->k = 0;
    esp->area_limite = 0;
    esp->preco_limite = 0;
}

//Leitura dos dados do arquivo espec.txt.
void le_espec(Espec esp, FILE * arq)
{
    fscanf(arq, "%d ", &esp->percent_caros);
    fscanf(arq, "%d ", &esp->percent_argiloso);
    fscanf(arq, "%f ", &esp->area_limite);
    fscanf(arq, "%f ", &esp->preco_limite);
    fscanf(arq, "%d %d %d", &esp->i,
                            &esp->j,
                            &esp->k);
}

// Identificadores referente as posicoes i, j e k estabelecidas pelo arquivo espec.txt
struct identificadores
{
    unsigned int i, j, k;
};

//Iguala todos identificadores a 0;
void inicializa_identificadores(Identificadores id)
{
    id->i = 0;
    id->j = 0;
    id->k = 0;
}

int espec_imovel_limite(int area, int preco, Espec espec)
{
    if(area > espec->area_limite && preco < espec->preco_limite)
    {
        return 1;
    }

    return 0;   
}

void imprime_soma_id(Identificadores id)
{
    printf("%d\n", id->i + id->j + id->k);
}