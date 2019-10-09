#ifndef _COMP
    #define _COMP
    #define EXP_COMP 10
    #include "pais.h"

    typedef struct{
        tPais * paises;
        int qtd_paises;
        int max_paises;
    } tCompeticao;

    void inicializa_competicao(tCompeticao *);
    void atualiza_competicao(tCompeticao *, tPais*);
    void apresenta_competicao(tCompeticao *);
    void ordena_competicao(tCompeticao *, int (*cmp)(tPais *, tPais *));
    void libera_competicao(tCompeticao *);
#endif