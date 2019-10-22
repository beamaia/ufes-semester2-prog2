#include <stdio.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"

void le_categoria(tCategoria *cat, int tipo, FILE * arq)
{
    switch (tipo)
    {
        case 1: le_triangulo(&cat->tri, arq);
                return;
        case 2: le_retangulo(&cat->ret, arq);
                return;
        case 3: le_trapezio(&cat->tra, arq);
                return;
        case 4: le_casa(&cat->casa, arq);
                return;
        case 5: le_apartamento(&cat->apto, arq);
    }
}

float preco_imovel_categoria(tCategoria * cat, int tipo)
{
    switch (tipo)
    {
        case 1: return preco_triangulo(&cat->tri);
        case 2: return preco_retangulo(&cat->ret);
        case 3: return preco_trapezio(&cat->tra);
        case 4: return preco_casa(&cat->casa);
        case 5: return preco_apartamento(&cat->apto);
    }
}

float area_imovel_categoria(tCategoria * cat, int tipo)
{
    switch(tipo)
    {
        case 1: return area_triangulo(&cat->tri);
        case 2: return area_retangulo(&cat->ret);
        case 3: return area_trapezio(&cat->tra);
        case 4: return area_casa(&cat->casa);
        case 5: return area_apartamento(&cat->apto);
    }

    return 0;
}

int categoria_compara_quartos(tCategoria *cat1, tCategoria *cat2)
{
    return casa_compara_quartos(&cat1->casa, &cat2->casa);
}

int categoria_identifica_argiloso(tCategoria *cat, int tipo)
{
    switch(tipo)
    {
        case 1: return solo_argilosos_triangulo(&cat->tri);
        case 2: return solo_argilosos_traprezio(&cat->tra);
        case 3: return solo_argilosos_retangulo(&cat->ret);
    }

    return 0;
}
