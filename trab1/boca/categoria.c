#include <stdio.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "espec.h"

/*
Com base no tipo de imovel que e (triangulo, retangulo, trapezio, casa ou apartamento),
chama a funcao de leitura necessaria.
*/
int le_categoria(tCategoria *cat, int tipo, FILE * arq)
{
    switch (tipo)
    {
        case 1: le_triangulo(&cat->tri, arq);
                return 1;
        case 2: le_retangulo(&cat->ret, arq);
                return 1;
        case 3: le_trapezio(&cat->tra, arq);
                return 1;
        case 4: le_casa(&cat->casa, arq);
                return 1;
        case 5: le_apartamento(&cat->apto, arq);
                return 1;
        default: return 0;
    }
}

/*
Com base no tipo de imovel que e (triangulo, retangulo, trapezio, casa ou apartamento),
chama a funcao de calcular o preco do imovel necessaria.
*/
float categoria_preco_imovel(tCategoria * cat, int tipo)
{
    switch (tipo)
    {
        case 1: return preco_triangulo(&cat->tri);
        case 2: return preco_retangulo(&cat->ret);
        case 3: return preco_trapezio(&cat->tra);
        case 4: return preco_casa(&cat->casa);
        case 5: return preco_apartamento(&cat->apto);
        default: return 0;
    }
}

/*
Com base no tipo de imovel que e (triangulo, retangulo, trapezio, casa ou apartamento),
chama a funcao de calcular a area do imovel necessaria.
*/
float categoria_area_imovel(tCategoria * cat, int tipo)
{
    switch(tipo)
    {
        case 1: return area_triangulo(&cat->tri);
        case 2: return area_retangulo(&cat->ret);
        case 3: return area_trapezio(&cat->tra);
        case 4: return area_cons_casa(&cat->casa);
        case 5: return area_apartamento(&cat->apto);
        default: return 0;
    }
}

/*
Chama a funcao que compara a quantidade de quartos de duas casas. Retorna 1 caso casa da cat1
tem menos quartos que casa da cat2, 2 caso tenham a mesma quantidade e 0 se for maior.
*/
int categoria_compara_quartos(tCategoria *cat1, tCategoria *cat2)
{
    return casa_compara_quartos(&cat1->casa, &cat2->casa);
}

/*
Chama a funcao que retorna o tipo de solo do terreno de acordo com o tipo de terreno.
*/
int categoria_identifica_argiloso(tCategoria *cat, int tipo)
{
    switch(tipo)
    {
        case 1: return solo_argiloso_triangulo(&cat->tri);
        case 2: return solo_argiloso_retangulo(&cat->ret);
        case 3: return solo_argiloso_trapezio(&cat->tra);
        default: return 0;
    }
}