#ifndef _COMODO
    #include "ponto.h"
    #include "retangulo.h"
    #include "circulo.h"
    #include "triangulo.h"
    #define _COMODO

    typedef union{
        tTriangulo t;
        tRetangulo r;
        tCirculo c;
    } tForma;

    typedef struct{
        tForma forma;
        int area, perimetro;
        char tag;
    } tComodo;

    void leia_comodo(tComodo *);
    void apresenta_comodo(tComodo *);
    void area_comodo(tComodo *);
    void perimetro_comodo(tComodo *);
    int compara_area(tComodo *, tComodo *);
    int compara_perimetro(tComodo *, tComodo *);
#endif