#include <stdio.h>
#include "residencia.h"

//Leitura da quantidade de quartos e vagas da residencia
void le_residencia(tResidencia *res, FILE * arq)
{
    fscanf(arq, "%d%*c", &res->num_quartos);
    fscanf(arq, "%d%*c", &res->num_vagas);
}

//Compara a quantidade de quartos de duas residencias. Retorna 1 caso res1 tem mais quartos que res2, 2 caso tenham a mesma quantidade e 0 se for menor
int residencia_compara_quartos(tResidencia *res1, tResidencia *res2)
{
    if(res1->num_quartos > res2->num_quartos)
        return 1;
    
    if(res1->num_quartos == res2->num_quartos)
        return 2;
    
    return 0;
}