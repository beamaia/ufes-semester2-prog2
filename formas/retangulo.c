#include <stdio.h> 
#include <math.h>
#include "ponto.h"
#include "retangulo.h"

void leia_retangulo(tRetangulo *r)
{
    printf("\nDigite os pontos do canto inferior e do canto superior: \n");
    leia_ponto(&r->inf_dir);
    leia_ponto(&r->sup_esq);
    r->base = base_retangulo(&r->inf_dir, &r->sup_esq);
    r->altura = altura_retangulo(&r->inf_dir, &r->sup_esq);
}

float area_retangulo(tRetangulo *r)
{
    return r->base * r->altura;
}

float perimetro_retangulo(tRetangulo *r)
{
    return 2 * (r->base + r->altura);
}

void apresenta_retangulo(tRetangulo *r)
{
    printf("Forma: Retangular ");
    printf("Canto inferior direito: ");
    apresenta_ponto(&r->inf_dir);
    printf("Canto superior esquerdo: ");
    apresenta_ponto(&r->sup_esq);
}

int base_retangulo(tPonto *inf_dir, tPonto *sup_esq)
{
    return inf_dir->x - sup_esq->x;
}

int altura_retangulo(tPonto *inf_dir, tPonto *sup_esq)
{
    return sup_esq->y - inf_dir->y;
}