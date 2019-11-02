/*********************
Biblioteca categoria.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre a categoria 
do imovel.
*********************/
#ifndef _CATEGORIA
    #define _CATEGORIA
    #include <stdio.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apartamento.h"
    
    /*
    Dado referente ao tipo de imovel, podendo ser do tipo triangulo, retangulo, 
    trapezio, casa ou apartamento.
    */
    typedef union 
    {
        tTriangulo tri;
        tRetangulo ret;
        tTrapezio tra;
        tCasa casa;
        tApartamento apto;
    } tCategoria;

    int le_categoria(tCategoria *, int, FILE *);
    float categoria_preco_imovel(tCategoria *, int);
    float categoria_area_imovel(tCategoria *, int);
    int categoria_compara_quartos(tCategoria *, tCategoria *);
    int categoria_identifica_argiloso(tCategoria *, int);

#endif