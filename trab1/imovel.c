#include <stdio.h>
#include <string.h>
#include "terreno.h"
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "residencia.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "imovel.h"
#include "espec.h"

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


/*
Identifica qual e a categoria escolhida.
1: Triangulo
2: Retangulo
3: Trapezio
4: Casa
5: Apartamento
*/
int identifica_categoria(tImovel *imo)
{
    if(!strcmp(imo->categoria, "triang"))
        return 1;
    if(!strcmp(imo->categoria, "retang"))
        return 2;
    if(!strcmp(imo->categoria, "trapez"))
        return 3;
    if(!strcmp(imo->categoria, "casa"))
        return 4;
    if(!strcmp(imo->categoria, "apto"))
        return 5;
}

void le_imovel(tImovel *imo, FILE *arq)
{
    fscanf(arq, "%s%*c", imo->categoria);
    fscanf(arq, "%d%*c", &imo->id);
    fscanf(arq, "%[^\n]", &imo->nome_proprietario);
    
    int cat = identifica_categoria(imo);
    le_categoria(&imo->tipo_imovel, cat, arq);
}

void modifica_imovel(tImovel *imo1, tImovel *imo2)
{
    imo1 = imo2;
}

float preco_imovel(tImovel *imo)
{
    return preco_imovel_categoria(&imo->categoria, identifica_categoria(imo));
}

float area_imovel(tImovel *imo)
{
    return area_imovel_categoria(&imo->categoria, identifica_categoria(imo));
}

int imovel_limite_area_preco(tImovel *imo, tEspec *espec)
{
    if(imo->area > espec->area_limite && imo->preco < espec->preco_limite)
        return 1;
    
    return 0;
}

int compara_quartos(tImovel *imo1, tImovel *imo2)
{
    return compara_quartos(&imo1->tipo_imovel, &imo2->tipo_imovel);
}

int compara_preco(tImovel *imo1, tImovel *imo2)
{
    if(imo1->preco > imo2->preco)
        return 1;
    
    if(imo1->preco == imo2->preco)
        return 2;
    
    return 0;
}

int compara_area(tImovel *imo1, tImovel *imo2)
{
    if(imo1->area > imo2->area)
        return 1;
    
    if(imo1->area == imo2->area)
        return 2;
    
    return 0;
}