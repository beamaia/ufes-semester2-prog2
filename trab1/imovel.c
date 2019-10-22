#include <stdio.h>
#include <string.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "imovel.h"
#include "espec.h"

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

void preco_imovel(tImovel *imo)
{
    imo->preco = preco_imovel_categoria(&imo->categoria, identifica_categoria(imo));
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

int compara_id(tImovel *imo1, tImovel *imo2)
{
    return imo1->id == imo2->id;
}

int compara_quartos(tImovel *imo1, tImovel *imo2)
{
    int situacao = compara_quartos(&imo1->tipo_imovel, &imo2->tipo_imovel);
    if(situacao == 1 || (situacao == 2 && imo1->id > imo2->id))
        return 1;

    return 0;
}

int compara_preco(tImovel *imo1, tImovel *imo2)
{
    if(imo1->preco > imo2->preco || (imo1->preco == imo2->preco && imo1->id < imo2->id))
        return 1;

    return 0;
}

int compara_area(tImovel *imo1, tImovel *imo2)
{
    if(imo1->area < imo2->area || (imo1->area == imo2->area && imo1->id > imo2->id))
        return 1;
        
    return 0;
}

int identifica_id(tImovel *imo)
{
    return imo->id;
}

int imovel_identifica_argiloso(tImovel *imo)
{
    int tipo_solo = identifica_categoria(imo);
    if(categoria_identifica_argiloso(&c1->imoveis, tipo_solo))
        return 1;
    
    return
}

void imovel_apresenta_identificador(tImovel *imo)
{
    printf("%d ", imo->id);
}