#ifndef _CIRCULO
    #include "ponto.h"
    #define _CIRCULO

    typedef struct{
        tPonto origem;
        float raio;
    } tCirculo;

    void leia_circulo(tCirculo *);
    float area_circulo(tCirculo *);
    float perimetro_circulo(tCirculo *);
    void apresenta_circulo(tCirculo *);
#endif