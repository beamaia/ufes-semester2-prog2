#include <stdio.h>
#include <math.h>
#include "ponto.h"

void leia_ponto(tPonto *p)
{
    scanf("%d%d", &p->x, &p->y);
}

void apresenta_ponto(tPonto *p)
{
    printf("(%d, %d)", p->x, p->y);
}

int distancia(tPonto *p1, tPonto *p2)
{
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}