#include <stdio.h>
#include "apartamento.h"

//Leitura dos dados referente ao apartamento.
void le_apartamento(tApartamento *apto, FILE *arq)
{
    fscanf(arq, "%d\n", &apto->num_quartos);
    fscanf(arq, "%d\n", &apto->num_vagas);
    fscanf(arq, "%d\n", &apto->andar);
    fscanf(arq, "%f\n", &apto->area);
    fscanf(arq, "%d\n", &apto->preco);
    fscanf(arq, "%c\n", &apto->lazer);
    fscanf(arq, "%d\n", &apto->andares_total);
}

//Calcula o preco do apartamento.
float preco_apartamento(tApartamento *apto)
{
    float lazer = 1;
    if(apto->lazer == 'S')
        lazer = 1.15;
    
    return apto->preco * apto->area * (0.9 + ((float) apto->andar)/apto->andares_total) * lazer;
}

//Retorna a area do apartamento.
float area_apartamento(tApartamento *apto)
{
    return apto->area;
}