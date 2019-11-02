/*********************
Biblioteca apartamento.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre a residencia
tipo apartamento.
*********************/
#ifndef _APTO
    #define _APTO
    #include <stdio.h>

    /*
    Dados da residencia tipo apartamento. O andar que se situa e a quantidade de andares total
    do predio, o preco do m2 e a quantidade de quartos e vagas de garagem.
    */
    typedef struct 
    {
        unsigned int andar,
                     andares_total,
                     preco,
                     num_quartos,
                     num_vagas;
        float area;
        char lazer;
    } tApartamento;
    
    void le_apartamento(tApartamento *, FILE *);
    float preco_apartamento(tApartamento *);
    float area_apartamento(tApartamento *);

#endif