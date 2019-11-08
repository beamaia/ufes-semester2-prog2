#ifndef _APTO
    #define _APTO
    #include <stdio.h>
    typedef struct apartamento * Apartamento;

    Apartamento inicializa_apartamento();
    void le_apartamento(Apartamento, FILE *);
    float preco_apartamento(Apartamento);
    float area_apartamento(Apartamento);
    void libera_apartamento(Apartamento);
#endif