#ifndef _ESPEC
    #define _ESPEC
    #include <stdio.h>

    typedef struct 
    {
        unsigned int percent_caros,
                     percent_argiloso,
                     i,
                     j,
                     k;
        float area_limite,
              preco_limite;
    } tEspec;
    
    void le_espec(tEspec *, FILE *);

    typedef struct 
    {
        unsigned int i, j, k;
    } tIdentificadores;
    
#endif