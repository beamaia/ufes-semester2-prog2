#include <stdio.h>
#include <stdlib.h>
#include "casa.h"

/*
Dados da residencia tipo casa. Area do pavimento, area da regiao livre, a quantidade de
pavimentos, o preco do m2 da regiao pavimentada e livre, e a quantidade de quartos e vagas.
*/
struct casa
{
    float area_pav,
          area_livre;
    unsigned int num_pav,
                 preco_pav,
                 preco_livre,
                 num_quartos,
                 num_vagas;
};

Casa inicializa_casa()
{
    Casa casa;
    casa = (Casa) malloc(sizeof(struct casa));

    if(casa == NULL)
    {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    
    return casa;
}

void le_casa(Casa casa, FILE *arq)
{
    fscanf(arq, "%u\n", &casa->num_quartos);
    fscanf(arq, "%u\n", &casa->num_vagas);
    fscanf(arq, "%u\n", &casa->num_pav);
    fscanf(arq, "%f\n", &casa->area_pav);
    fscanf(arq, "%u\n", &casa->preco_pav);
    fscanf(arq, "%f\n", &casa->area_livre);
    fscanf(arq, "%u\n", &casa->preco_livre);
}

//Calcula o preco da casa.
float preco_casa(Casa casa)
{
    return (casa->preco_pav * casa->num_pav * casa->area_pav) + (casa->preco_livre * casa->area_livre); 
}

//Calcula a area de pavimento da casa a ser considerada para comparacoes futuras.
float area_cons_casa(Casa casa)
{
    return casa->area_pav * casa->num_pav;
}

/*
Compara a quantidade de quartos de duas casas. Retorna 1 caso casa1 tem menos quartos que casa2, 
2 caso tenham a mesma quantidade e 0 se for maior
*/
int casa_compara_quartos(Casa casa1, Casa casa2)
{
    if(casa1->num_quartos < casa2->num_quartos)
        return 1;
    
    if(casa1->num_quartos == casa2->num_quartos)
        return 2;
    
    return 0;
}

void libera_casa(Casa casa)
{
    free(casa);
}