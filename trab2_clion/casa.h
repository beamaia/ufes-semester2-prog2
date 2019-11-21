#ifndef _CASA
    #define _CASA
    #include <stdio.h>
    typedef struct casa * Casa;

    Casa inicializa_casa();   
    void le_casa(Casa, FILE *);
    float preco_casa(Casa);
    float area_cons_casa(Casa);
    int casa_compara_quartos(Casa, Casa);
    void libera_casa(Casa);

#endif