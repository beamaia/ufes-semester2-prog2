#ifndef _TRIANGULO
    #define _TRIANGULO
    #include <stdio.h>
    #include "terreno.h"

    typedef struct 
    {
        tTerreno ter;
        float base,
              altura,
              area;
    } tTriangulo;
    
    void le_triangulo(tTriangulo *,FILE *);
    float area_triangulo(tTriangulo *);
    float preco_triangulo(tTriangulo *);
#endif