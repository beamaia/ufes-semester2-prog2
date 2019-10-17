#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "competicao.h"

void inicializa_competicao(tCompeticao *c)
{
    c->time = (tTime *)malloc(sizeof(tTime) * QTD_ROD);
    c->qtd_times = 0;
    c->max_times = QTD_ROD;
}

void aumenta_competicao(tCompeticao *c)
{
    tTime *aux = c->time;
    c->time = (tTime *) malloc(sizeof(tTime)*(c->max_times + QTD_ROD));

    if(!c->time)
    {
        printf("Erro de memória em aumentar competição\n");
        exit(1);
    }

    int i;
    for(i = 0; i < c->qtd_times; i++)
    {
        c->time[i] = aux[i];
    }
    
    c->max_times += QTD_ROD;
    free(aux);
}

void atualiza_competicao(tCompeticao *c, tTime *t)
{
    if(!c->qtd_times)
        c->qtd_times = 1;
    
    for(int i = 0; i < c->qtd_times; i++)
    {
        if(compara_times(&c->time[i], t))
        {
            incrementa_time(&c->time[i], t);
            return;
        }
    }

    aumenta_competicao(c);
    c->time[c->qtd_times++] = *t;
}

void le_competicao(tCompeticao *c, FILE *fp)
{
    inicializa_competicao(c);
    int i = 0, len_aux;
    char aux[15];
    tTime t1, t2;
    while(feof(fp))
    {
        len_aux = le_nome_time(aux, fp);
        inicializa_time(&t1, len_aux);
        le_time(&t1, aux, fp);
        len_aux = le_nome_time(aux, fp);
        inicializa_time(&t2, len_aux);
        le_time(&t2, aux, fp);
        verifica_pontuacao_vitoria(&t1, &t2);

        atualiza_competicao(c, &t1);
        atualiza_competicao(c, &t2);
    }
}

void ordena_competicao(tCompeticao *c, int (* compara)(tTime *, tTime *))
{
    tTime aux;
    for(int i = 0; i < c->qtd_times - 1; i++)
    {
        for(int j = 0; j < c->qtd_times - i- 1; j++)
        {
            if((*compara)(&c->time[j], &c->time[j+1]))
            {
                aux = c->time[j];
                c->time[j] = c->time[j + 1];
                c->time[j + 1] = aux;
            }
        }
    }
}

void escreva_competica(tCompeticao *c, char tipo, FILE *fp)
{
    switch(tipo)
    {
        case 'g': fprintf(fp, "Ordenação por saldo de gols:\n");
                  break;
        case 'v': fprintf(fp, "Ordenação por vitórias:\n");
                  break;
        case 'p': fprintf(fp, "Ordenação por pontuação:\n");

    }
    for(int i = 0; i< c->qtd_times; i++)
    {
        escreva_time(&c->time[i], fp);
    }

    fprintf(fp, "\n");
}

void libera_competicao(tCompeticao *c)
{
    free(c);
}

void torneio(tCompeticao *c)
{
    FILE *fp = fopen("entrada.txt", "r");

    if(fp == NULL)
    {
        printf("Não foi informado o arquivo\n");
        exit(1);
    }

    le_competicao(jogo, fp);
    fclose(fp);
}

void ordenacao_torneio(tCompeticao *c)
{
    FILE *ft = fopen("saida.txt", "w");
    ordena_competicao(jogo, comapara_gols);
    escreva_competica(jogo,'g', ft);
    ordena_competicao(jogo, compara_ponto);
    escreva_competica(jogo, 'p', ft);
    ordena_competicao(jogo, compara_vitorias);
    escreva_competica(jogo, 'v', ft);
    fclose(ft);
}