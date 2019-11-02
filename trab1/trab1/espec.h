/*********************
Biblioteca espec.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre o arquivo espec.txt
e identificadores.
*********************/
#ifndef _ESPEC
    #define _ESPEC
    #include <stdio.h>

    /*
    Informacoes do arquivo espec.txt como a porcentagem de imoveis caros da lista a,
    a porcentagem de terrenos argilosos da lista b e a área e o preço limite das casas
    que irão compor a lista c, além da posicao dos identificadores que devem ser somados 
    (i, j, k) no final do programa.
    */
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

    // Identificadores referente as posicoes i, j e k estabelecidas pelo arquivo espec.txt
    typedef struct 
    {
        unsigned int i, j, k;
    } tIdentificadores;

    void inicializa_identificadores(tIdentificadores *);
    
#endif