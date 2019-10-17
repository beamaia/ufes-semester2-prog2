/*
 Entrada: Nome do time, gols, Nome do time, gols
 Empate : 1 ponto, Ganhar: 2 pontos
 Saida: Ponto, Vitorias, Saldo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTD_ROD 10

typedef struct{
    char * nome;
    int gols, pontos, vitorias;
} tTime;

int le_nome_time(char * aux, FILE *fp)
{
    fscanf(fp, "%s\n", aux);
    return strlen(aux);
}

void inicializa_time(tTime * t, int len)
{
    t->nome  = (char *) malloc(sizeof(char)*len);
    t->gols = t->pontos = t->vitorias = 0;
}

void le_time(tTime *t, char *aux, FILE *fp)
{
    strcpy(t->nome, aux);
    fscanf(fp, "%d%*c", &t->gols);
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

void incrimenta_time(tTime *t, tTime *aux)
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

typedef struct{
    tTime * time;
    int qtd_times, max_times;
} tCompeticao;

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
            incrimenta_time(&c->time[i], t);
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
        case 'g': fprintf(fp, "Ordenação por gols:\n");
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

int main()
{
    tCompeticao *jogo;
    FILE *fp = fopen("entrada.txt", "r");

    if(fp == NULL)
    {
        printf("Não foi informado o arquivo\n");
        exit(1);
    }

    inicializa_competicao(jogo);
    le_competicao(jogo, fp);
    fclose(fp);
    FILE *ft = fopen("saida.txt", "w");
    ordena_competicao(jogo, comapara_gols);
    escreva_competica(jogo,'g', ft);
    ordena_competicao(jogo, compara_ponto);
    escreva_competica(jogo, 'p', ft);
    ordena_competicao(jogo, compara_vitorias);
    escreva_competica(jogo, 'v', ft);
    fclose(ft);

    libera_competicao(jogo);
    return 0;
}
