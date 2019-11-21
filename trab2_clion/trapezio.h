#ifndef _TRAPEZIO
    #define _TRAPEZIO
    #include <stdio.h>
    typedef struct trapezio * Trapezio;
    
    Trapezio inicializa_trapezio();
    void le_trapezio(Trapezio, FILE *);
    float area_trapezio(Trapezio);
    float preco_trapezio(Trapezio);
    int solo_argiloso_trapezio(Trapezio);
    void libera_trapezio(Trapezio);
#endif