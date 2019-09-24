#include <stdio.h>
#include <math.h>
#include "ponto.h"

Ponto pto_cria (float x, float y)
{
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p)
{
    return p.x;
}

float pto_acessa_y (Ponto p)
{
    return p.y;
}

Ponto pto_atribui_x (Ponto p, float x)
{
    p.x = x;
    return p;
}


Ponto pto_atribui_y (Ponto p, float y)
{
    p.y = y;
    return p;
}

float pto_distancia (Ponto p1, Ponto p2)
{
    float x, y, dis;
    x = p1.x - p2.x;
    y = p1.y - p2.y;
    x = x * x;
    y = y * y;
    dis = sqrt(x + y);
    return dis;
}