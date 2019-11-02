/*********************
Biblioteca triangulo.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre o terreno tipo 
triangulo.
*********************/
#ifndef _TRIANGULO
    #define _TRIANGULO
    #include <stdio.h>

    //Dados do terrento tipo triangulo. Base, altura, tipo de solo e preco do m2
    typedef struct 
    {
        float base,
              altura;
        char solo;
        unsigned int preco;
    } tTriangulo;
    
    void le_triangulo(tTriangulo *,FILE *);
    float area_triangulo(tTriangulo *);
    float preco_triangulo(tTriangulo *);
    int solo_argiloso_triangulo(tTriangulo *);
    
#endif