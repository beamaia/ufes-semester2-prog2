#ifndef _PLANTA
    #include "ponto.h"
    #include "retangulo.h"
    #include "circulo.h"
    #include "triangulo.h"
    #include "planta.h"
    #define _PLANTA
    #define QTD_COM 100

    typedef struct{
        tComodos comodos[100];
        int area_total, perimetro_total;
        int qtd_comodos;
    } tPlanta;

    leia_planta(tPlanta *);
    apresenta_planta(tPlanta *);
    ordena(tPlanta *,  int(*compara)(tComodo *, tComodo *));
#endif