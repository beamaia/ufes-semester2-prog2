#ifndef _TRIANGULO
    #define _TRIANGULO
    #include <stdio.h>
    #include "terreno.h"

    typedef struct
    {
        float base;
        float altura;
        float area;
        tTerreno terreno;
    } tTriangulo;

    void le_triangulo(tTriangulo *, FILE *);
    void area_triangulo(tTriangulo *);
    float preco_triangulo(tTriangulo *);