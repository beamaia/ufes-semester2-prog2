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

    typedef struct imovel * Imovel;

    Imovel inicializa_imoveis();
    int identifica_categoria(Imovel);
    char *le_tipo_imovel(FILE *);
    char *le_nome_proprietario(FILE *);
    int le_imovel(Imovel, FILE *);
    void modifica_imovel(Imovel imo1, Imovel imo2);
void modifica_imovel_inclusao(Imovel imo1, Imovel imo2);
void modifica_imovel_alteracao(Imovel imo1, Imovel imo2);
        Imovel malloc_imovel(Imovel, int);
    void preco_imovel(Imovel);
    void area_imovel(Imovel);
    int imovel_limite_area_preco(Imovel, Espec);
    int compara_id(Imovel, Imovel);
    int compara_quartos(Imovel, Imovel);
    int compara_preco(Imovel, Imovel);
    int compara_area(Imovel, Imovel);
    void acrescenta_id(Imovel, unsigned int);
    unsigned int identifica_id(Imovel);
    int imovel_identifica_argiloso(Imovel);
    void imovel_apresenta_identificador(Imovel);
    void libera_imovel(Imovel);
void libera_imovel_nao_utilizado(Imovel imo);
#endif