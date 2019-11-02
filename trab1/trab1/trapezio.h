/*********************
Biblioteca trapezio.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre o terreno tipo 
trapezio.
*********************/
#ifndef _TRAPEZIO
    #define _TRAPEZIO
    #include <stdio.h>

    //Dados do terrento tipo trapezio. Base1, base2, altura, tipo de solo e preco do m2
    typedef struct 
    {
        float base1,
              base2,
              altura;
        char solo;
        unsigned int preco;
    } tTrapezio;
    
    void le_trapezio(tTrapezio *, FILE *);
    float area_trapezio(tTrapezio *);
    float preco_trapezio(tTrapezio *);
    int solo_argiloso_trapezio(tTrapezio *);

#endif