#include <stdio.h>
#include "terreno.h"

//Leitura do tipo de solo e o preco do m2 do terreno
void le_terreno(tTerreno * ter, FILE *arq)
{
    fscanf(arq, "%c%*c", &ter->solo);
    fscanf(arq, "%d%*c", &ter->preco);
}

//Fator que ira ser utilizado para calcular o preco do terreno
float fator_preco_terreno(tTerreno *ter)
{
    switch (ter->solo)
    {
        case 'A': return 0.9 * ter->preco;
        case 'G': return 1.3 * ter->preco;
        case 'R': return 1.1 * ter->preco;
    }
}