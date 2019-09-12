#ifndef _TRIANGULO  
    #include "ponto.h"
    #define _TRIANGULO  

    typedef struct{
        tPonto v1, v2, v3;
        float base, altura;
    } tTriangulo;

    void leia_triangulo(tTriangulo *);
    float area_triangulo(tTriangulo *);
    float perimetro_triangulo(tTriangulo *);
    void apresenta_triangulo(tTriangulo *);   
#endif