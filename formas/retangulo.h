#ifndef _RETANGULO
    #include "ponto.h"
    #define _RETANGULO

    typedef struct{
        tPonto inf_dir, sup_esq;
        float base, altura;
    } tRetangulo;

    void leia_retangulo(tRetangulo *);
    float area_retangulo(tRetangulo *);
    float perimetro_retangulo(tRetangulo *);
    void apresenta_retangulo(tRetangulo *);
    int base_retangulo(tPonto *, tPonto *);
    int altura_retangulo(tPonto *, tPonto *);
#endif