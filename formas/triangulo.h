#ifndef _TRIANGULO  
    #include "ponto.h"
    #define _TRIANGULO  

    typedef struct{
        tPonto v1, v2, v3;
        int base, altura;
    } tTriangulo;

    void leia_triangulo(tTriangulo *);
    int area_triangulo(tTriangulo *);
    int perimetro_triangulo(tTriangulo *);
    void apresenta_triangulo(tTriangulo *);   
#endif