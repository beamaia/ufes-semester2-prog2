#include <stdio.h>
#include "apartamento.h"

//Leitura dos dados referente ao apartamento.
void le_apartamento(tApartamento *apto, FILE *arq)
{
    fscanf(arq, "%d%*c", &apto->num_quartos);
    fscanf(arq, "%d%*c", &apto->num_vagas);
    fscanf(arq, "%d%*c", &apto->andar);
    fscanf(arq, "%f%*c", &apto->area);
    fscanf(arq, "%d%*c", &apto->preco);
    fscanf(arq, "%c%*c", &apto->lazer);
    fscanf(arq, "%d%*c", &apto->andares_total);
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