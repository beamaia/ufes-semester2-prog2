#include <stdio.h>
#include "ponto.h"

Ponto pto_cria (float x, float y);

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
Ponto pto_atribui_x (Ponto p, float x);

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y);

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2);