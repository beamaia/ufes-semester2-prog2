#ifndef _TRIANGULO
    #define _TRIANGULO
    #include <stdio.h>

    typedef struct 
    {
        float base,
              altura,
              area;
        char solo;
        unsigned int preco;
    } tTriangulo;
    
    void le_triangulo(tTriangulo *,FILE *);
    float area_triangulo(tTriangulo *);
    float preco_triangulo(tTriangulo *);
    int solo_argiloso_triangulo(tTriangulo *);

#endif