#ifndef _PLANTA
    #include "ponto.h"
    #include "retangulo.h"
    #include "circulo.h"
    #include "triangulo.h"
    #include "comodo.h"
    #define _PLANTA
    #define QTD_COM 100

    typedef struct planta{
        tComodo comodo[QTD_COM];
        int qtd_comodos;
    } tPlant;

    void leia_planta(tPlant *);
    void apresenta_planta(tPlant *);
    void ordena(tPlant *,  int(*compara)(tComodo *, tComodo *));
#endif