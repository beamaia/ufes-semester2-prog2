#ifndef _PLANTA
    #include "ponto.h"
    #include "retangulo.h"
    #include "circulo.h"
    #include "triangulo.h"
    #include "comodo.h"
    #define _PLANTA
    #define QTD_COM 100

    typedef struct{
        tComodo comodos[100];
        int qtd_comodos;
    } tPlanta;

    void leia_planta(tPlanta *);
    void apresenta_planta(tPlanta *);
    void ordena(tPlanta *,  int(*compara)(tComodo *, tComodo *));
#endif