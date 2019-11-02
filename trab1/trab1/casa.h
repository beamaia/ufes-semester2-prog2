/*********************
Biblioteca casa.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre a residencia
tipo casa.
*********************/
#ifndef _CASA
    #define _CASA
    #include <stdio.h>

    /*
    Dados da residencia tipo casa. Area do pavimento, area da regiao livre, a quantidade de
    pavimentos, o preco do m2 da regiao pavimentada e livre, e a quantidade de quartos e vagas.
    */
    typedef struct
    {
        float area_pav,
              area_livre;
        unsigned int num_pav,
                     preco_pav,
                     preco_livre,
                     num_quartos,
                     num_vagas;
    } tCasa;

    void le_casa(tCasa *, FILE *);
    float preco_casa(tCasa *);
    float area_cons_casa(tCasa *);
    int casa_compara_quartos(tCasa *, tCasa *);
#endif
    