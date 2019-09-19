#ifndef _DATA
    #define _DATA
    #include <stdio.h>
    typedef struct{
        int dia;
        int mes;
        int ano;
    } tData;

    void leia_data(tData *);
    int igualdade_data(tData, tData);
    int menor_data(tData, tData);
    void apresenta_data(tData, FILE *);
    void pergunta_data();
    
#endif