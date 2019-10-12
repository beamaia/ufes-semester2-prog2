#include <stdio.h>
#include "formas.h"

//Leitura de base e altura do triangulo
void le_triangulo(tTriangulo *t, FILE *fp)
{
    fscanf(fp, "%f %f", &t->base, &t->altura);
}

//Calcula a area do triangulo
float area_triangulo(tTriangulo *t)
{
    return (t->base * t->altura) / 2;
}

//Leitura dos lados do retangulo
void le_retangulo(tRetangulo *r, FILE *fp)
{
    fscanf(fp, "%f %f", &r->lado1, &r->lado2);
}

//Calcula a area do retangulo
float area_retangulo(tRetangulo *r)
{
    return r->lado1 * r->lado2;
}

//Leitura das bases e da altura do trapezio
void le_trapezio(tTrapezio *t, FILE *fp)
{
    fscanf(fp, "%f %f %f", &t->base1, &t->base2, &t->altura);
}

//Calcula a area do trapezio
float area_trapezio(tTrapezio *t)
{
    return (t->base1 + t->base2) * t->altura / 2;
}

//Chama funcao le_triangulo para leitura de dados do triangulo
void le_forma_triangulo(tForma *f, FILE *fp)
{
    le_triangulo(&f->triangulo, fp);
}

//Retorna valor da area do triangulo
int area_forma_triangulo(tForma *f)
{
    return area_triangulo(&f->triangulo);
}

//Chama funcao le_retangulo para leitura de dados do retangulo
void le_forma_retangulo(tForma *f, FILE *fp)
{
    le_retangulo(&f->retangulo, fp);
}

//Retorna valor da area do retangulo
int area_forma_retangulo(tForma *f)
{
    return area_retangulo(&f->retangulo);
}

//Chama funcao le_trapezio para leitura de dados do trapezio
void le_forma_trapezio(tForma *f, FILE * fp)
{
    le_trapezio(&f->trapezio, fp);
}

//Retorna valor da area do trapezio
int area_forma_trapezio(tForma *f)
{
    return area_trapezio(&f->trapezio);
}