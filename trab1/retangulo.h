#ifndef _RETANGULO
    #define _RETANGULO
    #include <stdio.h>

    typedef struct 
    {
        float lado1,
              lado2;
        char solo;
        unsigned int preco;
    } tRetangulo;
    
    void le_retangulo(tRetangulo *, FILE *);
    float area_retagulo(tRetangulo *);
    float preco_retangulo(tRetangulo *);
    int solo_argiloso_retangulo(tRetangulo *);

#endif