#include <stdio.h>
#include "terreno.h"
#include "trapezio.h"

//Leitura das informacoes do terreno tipo trapezio
void le_trapezio(tTrapezio *tra, FILE *arq)
{
    fscanf(arq, "%c%*c", &tra->solo);
    fscanf(arq, "%f%*c", &tra->preco);
    fscanf(arq, "%f%*c", &tra->base1);
    fscanf(arq, "%f%*c", &tra->base2);
    fscanf(arq, "%f%*c", &tra->altura);
}

//Calcula a area do terreno tipo trapezio
float area_trapezio(tTrapezio *tra)
{
    return (tra->base1 + tra->base2) * tra->altura / 2;
}

//Calcula o preco do terreno tipo trapezio
float preco_trapezio(tTrapezio *tra)
{
    float fator;
    switch (tra->solo)
    {
        case 'A': fator =  0.9 * tra->preco;
        case 'G': fator =  1.3 * tra->preco;
        case 'R': fator = 1.1 * tra->preco;
    }

    return area_trapezio(tra) * fator;
}

int solo_argiloso_trapezio(tTrapezio *tra)
{
    if(tra->solo == 'A')
        return 1;
    
    return 0;
}   