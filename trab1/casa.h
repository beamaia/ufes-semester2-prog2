/*
Biblioteca de funcoes e tipos relacionada a casa
*/
#ifndef _CASA
    #define _CASA
    #include <stdio.h>

    typedef struct 
    {
        unsigned int num_pav;
        float area_pav;
        unsigned int preco_pav;
        float area_livre;
        unsigned int preco_livre;
    } tCasa;
    
    void le_casa(tCasa *, FILE *fp);
    int calcula_preco_casa(tCasa *);
    int compara_area_casa(tCasa *, tCasa *, int, int);
#endif