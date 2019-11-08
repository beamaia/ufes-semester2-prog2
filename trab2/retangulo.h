#ifndef _RETANGULO
    #define _RETANGULO
    #include <stdio.h>
    typedef struct retangulo * Retangulo;

    Retangulo inicializa_retangulo();
    void le_retangulo(Retangulo, FILE *);
    float area_retangulo(Retangulo);
    float preco_retangulo(Retangulo);
    int solo_argiloso_retangulo(Retangulo);
    void libera_retangulo(Retangulo);
#endif