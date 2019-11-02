/*********************
Biblioteca retangulo.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre o terreno tipo 
retangulo.
*********************/
#ifndef _RETANGULO
    #define _RETANGULO
    #include <stdio.h>

    //Dados do terrento tipo retangulo. Lado1, lado2, tipo de solo e preco do m2
    typedef struct 
    {
        float lado1,
              lado2;
        char solo;
        unsigned int preco;
    } tRetangulo;
    
    void le_retangulo(tRetangulo *, FILE *);
    float area_retangulo(tRetangulo *);
    float preco_retangulo(tRetangulo *);
    int solo_argiloso_retangulo(tRetangulo *);

#endif