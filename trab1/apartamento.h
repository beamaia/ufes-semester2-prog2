#ifndef _APTO
    #define _APTO
    #include <stdio.h>
    #include "residencia.h"

    typedef struct 
    {
        tResidencia res;
        unsigned int andar,
                     preco,
                     andares_total;
        float area;
        char lazer;
    } tApartamento;
    
    void le_apartamento(tApartamento *, FILE *);
    float preco_apartamento(tApartamento *);
#endif