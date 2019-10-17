#ifndef _TORNEIO
    #define _TORNEIO
    #include "time.h"
    #include "jogo.h"
    #define EXP_TORNEIO 10
    typedef struct{
        tTime *tm;
        int qtd;
        int max;
    } tTorneio;

    void inicializaTorneio(tTorneio *);
    void processaTorneio(tTorneio *);
    tTime * procuraTimeTorneio(tTorneio *, tTorneio *);
    void inserirTimeTorneio(tTorneio *, tTorneio *);
    void atualizarTimeTorneio(tTorneio *, tTime *);
    void apresentaTabelaTorneio(tTorneio *);
    void apresentaNomesTimesTorneio(tTorneio *);
    void ordena(tTorneio *, int (*cmp)(tTime *, tTime *));
    void liberarTorneio(tTorneio *);
    void liberarTorneioExpande(tTorneio *);

#endif