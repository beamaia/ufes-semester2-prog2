#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "jogo.h"
#include "torneio.h"

void inicializaTorneio(tTorneio * tr)
{
    tr->qtd = 0;
    tr->tm = (tTime *) malloc(sizof(tTime) * EXP_TORNEIO);

    if(!tr->tm)
    {
        printf("deu ruim");
        exit(1);
    }

    tr->max = EXP_TORNEIO;
}

void processaTorneio(tTorneio *);
tTime * procuraTimeTorneio(tTorneio *, tTorneio *);
void inserirTimeTorneio(tTorneio *, tTorneio *);
void atualizarTimeTorneio(tTorneio *, tTime *);
void apresentaTabelaTorneio(tTorneio *);
void apresentaNomesTimesTorneio(tTorneio *);
void ordena(tTorneio *, int (*cmp)(tTime *, tTime *));
void liberarTorneio(tTorneio *);
void liberarTorneioExpande(tTorneio *);