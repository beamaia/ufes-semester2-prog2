#ifndef _CATALOGO
    #define _CATALOGO
        #include <stdio.h>
    #include <stdlib.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apto.h"
    #include "categoria.h"
    #include "imovel.h"
    typedef struct catalogo * Catalogo;

    Catalogo inicializa_catalogo();
    void expande_catalogo(Catalogo);
    void le_catalogo(Catalogo, FILE *);
    void altera_imovel(Catalogo, Imovel);
    void inclusao_imovel(Catalogo, Imovel);
    void exclusao_imovel(Catalogo, Imovel);
    void le_atual(Catalogo, FILE *);
    int tem_imoveis_no_catalogo(Catalogo);
    void calcula_preco(Catalogo);
    void calcula_area(Catalogo);
    void ordena(Catalogo, int (* cmp)(Imovel, Imovel));
    unsigned int calcula_qtd_caros(Catalogo, Espec);
    int calcula_qtd_argilosos(Catalogo, Espec);
    void catalogo_argiloso(Catalogo, Catalogo, Espec);
    void catalogo_casas(Catalogo, Catalogo, Espec);
    void imoveis_mais_caros(Catalogo, Espec, Identificadores);
    void terrenos_argilosos_menores(Catalogo, Catalogo, Identificadores, Espec);
    void casas_limite(Catalogo, Catalogo, Identificadores, Espec);
    void apresenta_imoveis_caros(Catalogo, int);
    void apresenta_terrenos_argilosos(Catalogo, int);
    void apresenta_casas_limite(Catalogo);
    void apresenta_catalogos(Catalogo, Catalogo, Catalogo, Identificadores, Espec);

#endif