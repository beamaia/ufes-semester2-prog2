#include <stdio.h>
#include <stdlib.h>
#include "apto.h"

struct apartamento 
{
    unsigned int andar,
                 andares_total,
                 preco,
                 num_quartos,
                 num_vagas;
    float area;
    char lazer;
};

Apartamento inicializa_apartamento()
{
    Apartamento apto;
    apto = (Apartamento) malloc(sizeof(struct apartamento));

    if(apto == NULL)
    {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    
    return apto;
}

//Leitura dos dados referente ao apartamento.
void le_apartamento(Apartamento apto, FILE *arq)
{
    fscanf(arq, "%u\n", &apto->num_quartos);
    fscanf(arq, "%u\n", &apto->num_vagas);
    fscanf(arq, "%u\n", &apto->andar);
    fscanf(arq, "%f\n", &apto->area);
    fscanf(arq, "%u\n", &apto->preco);
    fscanf(arq, "%c\n", &apto->lazer);
    fscanf(arq, "%u\n", &apto->andares_total);
}

//Calcula o preco do apartamento.
float preco_apartamento(Apartamento apto)
{
    float lazer = 1;
    if(apto->lazer == 'S')
        lazer = 1.15;
    
    return apto->preco * apto->area * (0.9 + ((float) apto->andar)/apto->andares_total) * lazer;
}

//Retorna a area do apartamento.
float area_apartamento(Apartamento apto)
{
    return apto->area;
}

void libera_apartamento(Apartamento apto)
{
    free(apto);
}
