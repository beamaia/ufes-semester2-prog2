#ifndef _CATEGORIA
    #define _CATEGORIA
    #include <stdio.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apartamento.h"
    #define MAX_NOME 40

    typedef union 
    {
        tTriangulo tri;
        tRetangulo ret;
        tTrapezio tra;
        tCasa casa;
        tApartamento apto;
    } tCategoria;

    void le_categoria(tCategoria *, int, FILE *);
    float preco_imovel_categoria(tCategoria *, int);
    float area_imovel_categoria(tCategoria *, int)
    int categoria_compara_quartos(tCategoria *, tCategoria *);
    int categoria_identifica_argiloso(tCategoria *, int)

#endif