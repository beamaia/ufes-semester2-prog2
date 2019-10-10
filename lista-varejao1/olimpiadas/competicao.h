#ifndef _COMPETICAO
    #define _COMPETICAO
    #define EXP_COMP 10
    #include "pais.h"

    typedef struct {
        tPais* pais;
        int quantidadePaises;
        int maxPaises;
    }tCompeticao;

    void inicializaCompeticao(tCompeticao* comp);
    void atualizaCompeticao(tCompeticao* comp, tPais* p);
    void apresentaCompeticao(tCompeticao* comp);
    void ordenaCompeticao(tCompeticao* comp, int (*troca) (tPais*, tPais*));
    void liberaCompeticao(tCompeticao* comp);

#endif