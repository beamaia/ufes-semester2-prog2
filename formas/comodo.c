#include <stdio.h> 
#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"
#include "comodo.h"
#include "planta.h"

char leia_tag(tComodo * com)
{
    scanf("%c ", &com->tag);
    return com->tag;
}

void leia_comodo(tForma * f, char tag)
{
    switch(tag)
    {
        case 'c':
            leia_circulo(&f->c);
            break; 
        case 't':
            leia_triangulo(&f->t);
            break;
        case 'r':
            leia_retangulo(&f->r);
            break;
        default: break;
    }
}

void apresenta_forma(tForma * f, char tag)
{
    switch(tag)
    {
        case 'c':
            apresenta_circulo(&f->c);
            break; 
        case 't':
            apresenta_triangulo(&f->t);
            break;
        case 'r':
            apresenta_retangulo(&f->r);
            break;
        default: break;
    }
}

void apresenta_comodo(tComodo * com)
{
    apresenta_forma(&com->forma, com->tag);
    printf("Area: %f", com->area);
    printf("Perimetro: %f\n", com->perimetro);
}

float area_comodo(tForma * f, char tag)
{
    int area;
    switch(tag)
    {
        case 'c':
            area = area_circulo(&f->c);
            break; 
        case 't':
            area = area_triangulo(&f->t);
            break;
        case 'r':
            area = area_retangulo(&f->r);
            break;
        default: break;
    } 

    return area;
}

float perimetro_comodo(tForma * f, char tag)
{
    int perimetro;
    switch(tag)
    {
        case 'c':
            perimetro = perimetro_circulo(&f->c);
            break; 
        case 't':
            perimetro = perimetro_triangulo(&f->t);
            break;
        case 'r':
            perimetro = area_retangulo(&f->r);
            break;
        default: break;
    } 

    return perimetro;
}

void area_perimetro(tComodo * com)
{
    com->area = area_comodo(&com->forma, com->tag);
    com->perimetro = perimetro_comodo(&com->forma, com->tag);
}

int compara_area(tComodo * com1, tComodo * com2)
{
    return com1->area > com2->area;
}

int compara_perimetro(tComodo * com1, tComodo * com2)
{
    return (com1->perimetro > com2->perimetro);
}