#include <stdio.h>
#include "residencia.h"
#include "casa.h"

//Leitura dos dados referente a casa
void le_casa(tCasa *casa, FILE *arq)
{
    le_residencia(&casa->res, arq);
    fscanf(arq, "%d%*c", &casa->num_pav);
    fscanf(arq, "%f%*c", &casa->area_pav);
    fscanf(arq, "%d%*c", &casa->preco_pav);
    fscanf(arq, "%f%c", &casa->area_livre);
    fscanf(arq, "%d%*c", &casa->preco_livre);
}

//Calcula o preco da casa
float preco_casa(tCasa *casa)
{
    return (casa->preco_pav * casa->num_pav * casa->area_pav) + (casa->preco_livre * casa->area_livre); 
}

//Calcula a area da casa a ser considerada para comparacoes futuras
float area_cons_casa(tCasa *casa)
{
    return casa->area_pav * casa->num_pav;
}

//Compara a quantidade de quartos de duas casas. Retorna 1 caso casa1 tem mais quartos que casa2, 2 caso tenham a mesma quantidade e 0 se for menor
int casa_compara_quartos(tCasa *casa1, tCasa *casa2)
{
    return compara_quartos(&casa1->res, &casa2->res);
}
