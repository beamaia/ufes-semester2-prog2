#include <stdio.h>
#include "terreno.h"

void le_terreno(tTerreno *t, FILE *fp)
{
    fscanf(fp, "%c%*c%f%*c", &t->solo,
                             &t->preco_m2)
}

float mult_preco_e_solo_terreno(tTerreno *);
