#include <stdio.h>
#include "casa.h"

//Leitura dos dados referente a casa.
void le_casa(tCasa *casa, FILE *arq)
{
    fscanf(arq, "%d%*c", &casa->num_quartos);
    fscanf(arq, "%d%*c", &casa->num_vagas);
    fscanf(arq, "%d%*c", &casa->num_pav);
    fscanf(arq, "%f%*c", &casa->area_pav);
    fscanf(arq, "%d%*c", &casa->preco_pav);
    fscanf(arq, "%f%*c", &casa->area_livre);
    fscanf(arq, "%d%*c", &casa->preco_livre);
}

//Calcula o preco da casa.
float preco_casa(tCasa *casa)
{
    return (casa->preco_pav * casa->num_pav * casa->area_pav) + (casa->preco_livre * casa->area_livre); 
}

//Calcula a area de pavimento da casa a ser considerada para comparacoes futuras.
float area_cons_casa(tCasa *casa)
{
    return casa->area_pav * casa->num_pav;
}

/*
Compara a quantidade de quartos de duas casas. Retorna 1 caso casa1 tem menos quartos que casa2, 
2 caso tenham a mesma quantidade e 0 se for maior
*/
int casa_compara_quartos(tCasa *casa1, tCasa *casa2)
{
    if(casa1->num_quartos < casa2->num_quartos)
    {
        return 1;
    }
    
    if(casa1->num_quartos == casa2->num_quartos)
    {
        return 2;
    }
    
    return 0;
}