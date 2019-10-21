#include <stdio.h>
#include "terreno.h"
#include "trapezio.h"

//Leitura das informacoes do terreno tipo trapezio
void le_trapezio(tTrapezio *tra, FILE *arq)
{
    le_terreno(&tra->ter, arq);
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
    return area_trapezio(tra) * fator_preco_terreno(&tra->ter);
}