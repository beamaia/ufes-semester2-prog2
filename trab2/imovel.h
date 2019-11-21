#ifndef _IMOVEL
    #define _IMOVEL
    #include <stdio.h>
    #include <stdlib.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apto.h"
    #include "categoria.h"
    #define MAX_IMO 50

    typedef struct imovel * Imovel;

    void inicializa_imoveis(Imovel *, unsigned int);
    int identifica_categoria(Imovel);
    void le_tipo_imovel(char *, FILE *);
    void le_nome_proprietario(char *, FILE *);
    int le_imovel(Imovel, FILE *);
    Imovel malloc_imovel(Imovel, int);
    void preco_imovel(Imovel);
    void area_imovel(Imovel);
    int imovel_limite_area_preco(Imovel, Espec);
    int compara_id(Imovel, Imovel);
    int compara_quartos(Imovel, Imovel);
    int compara_preco(Imovel, Imovel);
    int compara_area(Imovel, Imovel);
    void acrescenta_id(Imovel, int);
    int identifica_id(Imovel);
    int imovel_identifica_argiloso(Imovel);
    void imovel_apresenta_identificador(Imovel);
    void libera_imovel(Imovel);
#endif