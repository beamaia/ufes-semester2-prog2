#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "time.h"

void inicializaTime(tTime *t, char *n, int p, int c) // p -> pros c->contra
{
    t->nome = (char *) malloc(sizeof(char) * (strlen(n) + 1));
    strcpy(t->nome. n);

    if(p > c)
    {
        t->pts = 3;
        t->vits = 1;
    }
    else
    {
        if(p < c)
        {
            t->pts = 0;
            t->vits = 0;
        }
        else
        {
            t->pts = 1;
            t->vits = 0;
        }
    }

    t->pros = p;
    t->cts = c;
    t->sd = p - c;
}

void apresentaTime(tTime *t)
{
    printf("Nome: %s Vitorias: %d Marcadps: %d Sofrido: %d Saldo: %d\n", t->nome,
                                                                         t->vits,
                                                                         t->pros,
                                                                         t->cts, 
                                                                         t->sd);
}

void atualizaTime(tTime *t, tTime *v)
{
    t->vits += v->vits;
    t->pts += v->pts;
    t->pros += v->pros;
    t->cts += v->cts;
    t->sd += v->sd;
}

int cmpNomeTimes(tTime *t1, tTime *t2)
{
    return strcmp(t1->nome, t2->nome);
}

int cmpTimes(tTime *t1, tTime *t2)
{
    if(t2->pts > t1->pts)
        return 1;
    
    if(t2->pts == t1->pts && t2->vits == t1->vits && t2->sd > t1->sd) 
        return 1;

    if(t2->pts == t1->pts && t2->vits == t1->vits && t1->sd == t2->sd && t2->pros > t1->pros)
    {
        return 1;
    }

    if(t2->pts == t1->pts && t2->vits == t1->vits && t1->sd == t2->sd && t2->pros == t1->pros)
    {
        return (cmpNomesTimes(t1, t2) < 0);
    }
}

int cmpPros(tTime *t1, tTime *t2)
{
    if(t1->pros > t2->pros)
    {
        return 0;
    }
    if(t1->pros < t2->pros)
    {
        return 1;
    }
    return (compNomesTimes(t1, t2) < 0);
}

int cmpContras(tTime *t1, tTime *t2)
{
    if(t1->cts > t2->cts)
        return 1;

    if(t1->cts < t2->cts)
        return 1;
        
    return (cmpNomesTimes(t1, t2)  0);
}

int cmpVitorias(tTime *t1, tTime *t2)
{
    if(t1->vits > t2->vits)
        return 1;
    
    if(t1->vits < t2->vits)
        return 0;
    
    return (cmpNomesTimes(t1, t2)  0);
}

void liberaNomeTime(tTime *t)
{
    free(t->nome);
}