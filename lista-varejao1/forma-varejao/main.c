#include <stdio.h>
#include "pais.h"
#include "competicao.h"

void main()
{
    tCompeticao comp;
    tPais aux;
    int cod;
    inicializa_competicao(&comp);
    scanf("%d", &cod);
    inicializa_pais(&aux,cod);

}