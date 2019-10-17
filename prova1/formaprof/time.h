#ifndef _TIME
    #define _TIME
    typedef struct{
        char *nome;
        int pts,
            vits,
            pros,
            cts,
            sd;
    } tTime;

    void inicializaTime(tTime *, char *, int, int);
    void apresentaTime(tTime *);
    void atualizaTime(tTime *);
    int cmpTimes(tTime *, tTime *); //pontos
    int cmpContras(tTime *, tTime *); //crescente
    int cmpPros(tTime *, tTime *); // decrescente
    int cmpVitorias(tTime *, tTime *); //crescente
    void apresentaNomeTime(tTime *);
    int compNomeTimes(tTime *, tTime *);
    void liberaNomeTimes(tTime *, tTime *);
#endif