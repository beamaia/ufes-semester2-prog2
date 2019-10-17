#ifndef _COMP
    #define _COMP
    #include "time.h"
    #define QTD_ROD 10
    
    typedef struct{
        tTime * time;
        int qtd_times, max_times;
    } tCompeticao;

    void inicializa_competicao(tCompeticao *c);
    void aumenta_competicao(tCompeticao *c);
    void atualiza_competicao(tCompeticao *c, tTime *t);
    void le_competicao(tCompeticao *c, FILE *fp);
    void ordena_competicao(tCompeticao *c, int (* compara)(tTime *, tTime *));
    void escreva_competica(tCompeticao *c, char tipo, FILE *fp);
    void libera_competicao(tCompeticao *c);
    void torneio(tCompeticao *c);
    void ordenacao_torneio(tCompeticao *c);
#endif