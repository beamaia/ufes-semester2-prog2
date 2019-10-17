#include <stdio.h>
#include <stdlib.h>
#include <string.>
#include "jogo.h"
#include "time.h"

int le_nome_time(char * aux, FILE *fp)
{
    fscanf(fp, "%s\n", aux);
    return strlen(aux);
}

void le_time(tTime *t, char *aux, FILE *fp)
{
    strcpy(t->nome, aux);
    fscanf(fp, "%d%*c", &t->gols);
}

void inicializa_time(tTime * t, int len)
{
    t->nome  = (char *) malloc(sizeof(char)*(len + 1);
    t->gols = t->pontos = t->vitorias = 0;
}

void verifica_pontuacao_vitoria(tTime *t1, tTime *t2)
{
    if(t1->gols > t2->gols)
    {
        t1->pontos = 2;
        t1->vitorias = 1;
        return;
    }

    if(t1->gols < t2->gols)
    {
        t2->pontos = 2;
        t1->vitorias = 1;
        return;
    }

    if(t1->gols == t2->gols)
    {
        t1->pontos = 1;
        t2->pontos = 1;
    }
}

void incrementa_time(tTime *t, tTime *aux)
{
    t->gols += aux->gols;
    t->pontos += aux->pontos;
    t->vitorias += aux->vitorias;
}

int compara_ponto(tTime *t1, tTime *t2)
{
    return t1->pontos > t2->pontos;
}

int compara_vitorias(tTime *t1, tTime *t2)
{
    return t1->vitorias > t2->vitorias;
}

int comapara_gols(tTime *t1, tTime *t2)
{
    return t1->gols > t2->gols;
}

int compara_times(tTime *t1, tTime *t2)
{
    return !strcmp(t1->nome, t2->nome);
}

void escreva_time(tTime *t, FILE *fp)
{
    fprintf(fp, "Time: %s Pontuação: %d Gols: %d Vitorias: %d\n", t->nome,
                                                                  t->pontos,
                                                                  t->gols,
                                                                  t->vitorias);
}