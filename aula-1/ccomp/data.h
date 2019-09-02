#ifndef _DATA
    #define _DATA

    typedef struct{
        int dia;
        int mes;
        int ano;
    } tData;

    tData leia_data();
    int igualdade_data(tData, tData);
    int menor_data(tData, tData);
    void apresenta_data(tData);
    void pergunta_data();
    
#endif