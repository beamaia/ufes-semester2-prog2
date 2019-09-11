#ifndef _CIRCULO
    #include "ponto.h"
    #define _CIRCULO

    typedef struct{
        tPonto origem;
        int raio;
    } tCirculo;

    void leia_circulo(tCirculo *);
    int area_circulo(tCirculo *);
    int perimetro_circulo(tCirculo *);
    void apresenta_circulo(tCirculo *);
#endif