#ifndef _TRIANGULO
    #define _TRIANGULO
    #include <stdio.h>
    typedef struct triangulo * Triangulo;

    Triangulo inicializa_triangulo();
    void le_triangulo(Triangulo, FILE *);
    float area_triangulo(Triangulo);
    float preco_triangulo(Triangulo);
    int solo_argiloso_triangulo(Triangulo);
#endif