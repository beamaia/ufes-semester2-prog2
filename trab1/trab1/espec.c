#include <stdio.h>
#include "espec.h"

//Leitura dos dados do arquivo espec.txt.
void le_espec(tEspec * esp, FILE * arq)
{
    fscanf(arq, "%d%*c", &esp->percent_caros);
    fscanf(arq, "%d%*c", &esp->percent_argiloso);
    fscanf(arq, "%f%*c", &esp->area_limite);
    fscanf(arq, "%f%*c", &esp->preco_limite);
    fscanf(arq, "%d%*c%d%*c%d%*c", &esp->i,
                                   &esp->j,
                                   &esp->k);
}

//Iguala todos identificadores a 0;
void inicializa_identificadores(tIdentificadores *id)
{
    id->i = 0;
    id->j = 0;
    id->k = 0;
}
