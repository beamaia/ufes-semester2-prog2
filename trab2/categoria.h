#ifndef _CATEGORIA
    #define _CATEGORIA
    #include <stdio.h>
    #include <stdlib.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apto.h"
    typedef union categoria * Categoria;

    Categoria inicializa_union();
    Categoria inicializa_categoria(int tipo);
    int le_categoria(Categoria cat, int tipo, FILE * arq);
    float categoria_preco_imovel(Categoria, int);
    float categoria_area_imovel(Categoria, int);
    int categoria_compara_quartos(Categoria, Categoria);
    int categoria_identifica_argiloso(Categoria, int);
    void libera_categoria(Categoria, int);
#endif