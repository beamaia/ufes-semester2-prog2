#ifndef _TIME
    #define _TIME
    #include <stdio.h>
    typedef struct{
        char *nome;
        int gols, pontos, vitorias;
    } tTime;

    void inicializa_time(tTime *, int);
    void le_time(tTime *, char *, FILE *);
    void verifica_pontuacao_vitoria(tTime *, tTime *);
    void incrementa_time(tTime *, tTime *);
    int compara_ponto(tTime *, tTime *);
    int compara_vitorias(tTime *, tTime *);
    int comapara_gols(tTime *, tTime *);
    int compara_times(tTime *, tTime *);
    void escreva_time(tTime *, FILE *);
#endif