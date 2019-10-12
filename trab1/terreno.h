/*
Biblioteca para tipos e funcoes relacionadas ao terreno.
*/
#ifndef _TERRENO
    #define _TERRENO
    #define TAG_TER 6
    #include <stdio.h>
    #include "formas.h"

    typedef struct 
    {
        char solo;
        unsigned int preco_m2;
        unsigned int area;
        tForma forma;
        char tag[TAG_TER];
    } tTerreno;

    void le_solo(tTerreno *, FILE *);
    void le_terreno(tTerreno *, char, FILE *);
    void area_terreno(tTerreno *);
    int compara_area_terreno(tTerreno *, tTerreno *, int, int); 

#endif