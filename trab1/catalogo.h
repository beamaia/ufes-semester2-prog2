#ifndef _CATALOGO
    #define _CATALOGO
    #include <stdio.h>
    #include "imovel.h"
    #include "espec.h"
    #define MAX_IMO 300

    typedef struct 
    {
        tImovel imoveis[MAX_IMO];
        unsigned int qtd_imoveis;
    } tCatalogo;
    
    void inicializa_catalogo(tCatalogo *);
    void le_catalogo(tCatalogo *, FILE *);
    void le_atual(tCatalogo *, FILE *);
    void inclusao_imovel(tCatalogo *, tImovel *);
    void exclusao_imovel(tCatalogo *);
    void altera_imovel(tCatalogo *, tImovel *);
    void calcula_preco(tCatalogo *);
    void ordena(tCatalogo *, int (* cmp)(tImovel, tImovel));
    int calcula_qtd_caros(tCatalogo *, tCatalogo *, tEspec *);
    void imoveis_mais_caros(tCatalogo *, tEspec *, tIdentificadores);
    int calcula_qtd_argilosos(tCatalogo *, tEspec *);
    void catalogo_argiloso(tCatalogo *, tCatalogo *, tEspec *);
    void terrenos_argilosos_menores(tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);
    void catalogo_casas(tCatalogo *, tCatalogo *, tEspec *);
    void casas_limite(tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);
    void apresenta_imoveis_caros(tCatalogo *);
    void apresenta_terrenos_argilosos(tCatalogo *);
    void apresenta_casas_limite(tCatalogo *);
    void apresenta_catalogos(tCatalogo *, tCatalogo *, tCatalogo *, tIdentificadores *);

#endif