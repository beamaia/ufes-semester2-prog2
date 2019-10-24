#include <stdio.h>
#include "trapezio.h"

//Leitura das informacoes do terreno tipo trapezio
void le_trapezio(tTrapezio *tra, FILE *arq)
{
    fscanf(arq, "%c%*c", &tra->solo);
    fscanf(arq, "%d%*c", &tra->preco);
    fscanf(arq, "%f%*c", &tra->base1);
    fscanf(arq, "%f%*c", &tra->base2);
    fscanf(arq, "%f%*c", &tra->altura);
}

//Calcula a area do terreno tipo trapezio
float area_trapezio(tTrapezio *tra)
{
    float x = ((tra->base1 + tra->base2) * tra->altura) / ((float) 2.0);
    return x;
}

//Calcula o preco do terreno tipo trapezio
float preco_trapezio(tTrapezio *tra)
{
    float fator = 0;
    switch (tra->solo)
    {
        case 'A': fator = 0.9 * ((float) tra->preco);
                  break;
        case 'G': fator = 1.3 * ((float) tra->preco);
                  break;
        case 'R': fator = 1.1 * ((float) tra->preco);
    }

    return area_trapezio(tra) * fator;
}

//Verifica se o solo do terreno tipo trapezio e argiloso
int solo_argiloso_trapezio(tTrapezio *tra)
{
    if(tra->solo == 'G')
        return 1;
    
    return 0;
}   