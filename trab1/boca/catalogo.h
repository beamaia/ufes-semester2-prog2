/*********************
Biblioteca catalogo.h
Funcoes e structs utilizados para a manipulacao de informacoes sobre o catalogo.
*********************/
#ifndef _CATALOGO
    #define _CATALOGO
    #include <stdio.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apartamento.h"
    #include "categoria.h"
    #include "imovel.h"
    #include "espec.h"
    #define MAX_IMO 300 //quantidade maxima de imoveis permitida no catalogo

    //Dados do catalogo. Um catalogo de varios imoveis e a quantidade de imoveis nesse catalogo.
    typedef struct 
    {
        tImovel imoveis[MAX_IMO];
        unsigned int qtd_imoveis;
    } tCatalogo;
    
    void inicializa_catalogo(tCatalogo *);
    void le_catalogo(tCatalogo *, FILE *);
    void altera_imovel(tCatalogo *, tImovel *);
    void inclusao_imovel(tCatalogo *, tImovel *);
    void exclusao_imovel(tCatalogo *, tImovel *);
    void le_atual(tCatalogo *, FILE *);
    void calcula_preco(tCatalogo *);
    void calcula_area(tCatalogo *);
    void ordena(tCatalogo *, int (* cmp)(tImovel *, tImovel *));
    int calcula_qtd_caros(tCatalogo *, tEspec *);
    int calcula_qtd_argilosos(tCatalogo *, tEspec *);
    void catalogo_argiloso(tCatalogo *, tCatalogo *, tEspec *);
    void catalogo_casas(tCatalogo *, tCatalogo *, tEspec *);
    void imoveis_mais_caros(tCatalogo *, tEspec *, tIdentificadores *);
    void terrenos_argilosos_menores(tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);
    void casas_limite(tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);
    void apresenta_imoveis_caros(tCatalogo *, int);
    void apresenta_terrenos_argilosos(tCatalogo *, int);
    void apresenta_casas_limite(tCatalogo *);
    void apresenta_catalogos(tCatalogo *, tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);

#endif