#ifndef _RETANGULO
    #include "ponto.h"
    #define _RETANGULO

    typedef struct{
        tPonto inf_dir, sup_esq;
        int base, altura;
    } tRetangulo;

    void leia_retangulo(tRetangulo *);
    int area_retangulo(tRetangulo *);
    int perimetro_retangulo(tRetangulo *);
    void apresenta_retangulo(tRetangulo *);
    int base_retangulo(tPonto *, tPonto *);
    int altura_retangulo(tPonto *, tPonto *);
#endif