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
        float area, perimetro;
        char tag;
    } tComodo;

    char leia_tag(tComodo *);
    void leia_comodo(tForma *, char);
    void apresenta_forma(tForma *, char);
    void apresenta_comodo(tComodo *);
    float area_comodo(tForma *, char);
    float perimetro_comodo(tForma *, char);
    void area_perimetro(tComodo *);
    int compara_area(tComodo *, tComodo *);
    int compara_perimetro(tComodo *, tComodo *);
#endif