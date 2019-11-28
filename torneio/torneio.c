#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_JOGOS 10
#define MAX_NAME 40

typedef struct
{
    char *nome;
    int pontos,
        vitorias,
        marcados,
        sofridos,
        saldo;
} Time;

Time inicializa_time()
{
    Time t;
    t.pontos = 0;
    t.marcados = 0;
    t.saldo = 0;
    t.sofridos = 0;
    t.vitorias = 0;

    return t;
}

int le_nome(char *aux)
{
    if(scanf("%s", aux))
        return (int) strlen(aux);
    return 0;
}

int le_time(Time *t)
{
    int tam;
    char aux[MAX_NAME];
    if(scanf("%s %d", aux, &t->marcados) == 2)
    {
        t->nome = (char *) malloc(sizeof(char) * (tam + 1));
        strcpy(t->nome, aux);
        return 1;
    }
    return 0;
}

void ponto_dos_times(Time *t1, Time *t2) {
    t1->sofridos = t2->marcados;
    t2->sofridos = t1->marcados;
    t1->saldo = t1->marcados - t2->marcados;
    t2->saldo = t2->marcados - t1->marcados;

    if (t1->marcados > t2->marcados)
    {
        t1->vitorias++;
        t1->pontos = 3;
    } else if (t1->saldo < t2->saldo)
    {
        t2->vitorias++;
        t2->pontos = 3;
    }
    else
    {
        t1->pontos = t2->pontos = 1;
    }
}

void modifica_time(Time *t, Time *aux)
{
    t->pontos += aux->pontos;
    t->sofridos += aux->sofridos;
    t->saldo += aux->saldo;
    t->marcados += aux->marcados;
    t->vitorias += aux->vitorias;
}

void copia_time(Time *t, Time *aux)
{
    t->nome = (char *) malloc(sizeof(char) * (strlen(aux->nome) + 1));
    modifica_time(t, aux);
    strcpy(t->nome, aux->nome);
}

int times_iguais(Time *t1, Time *t2)
{
    return !strcmp(t1->nome, t2->nome);
}

int compara_nomes_times(Time *t1, Time *t2)
{
    return strcmp(t1->nome, t2->nome) > 0;
}

int compara_marcados(Time *t1, Time *t2)
{
    if(t1->marcados < t2->marcados)
        return 1;
    else if(t1->marcados == t2->marcados)
        return compara_nomes_times(t1, t2);

    return 0;
}

int compara_saldo(Time *t1, Time *t2)
{
    if(t1->saldo < t2->saldo)
        return 1;
    else if(t1->saldo == t2->saldo)
        return compara_marcados(t1, t2);

    return 0;
}

int compara_vitorias(Time *t1, Time *t2)
{
    if(t1->vitorias < t2->vitorias)
        return 1;
    else if(t1->vitorias == t2->vitorias)
        return compara_saldo(t1, t2);

    return 0;
}

int compara_pontos(Time *t1, Time *t2)
{
    if(t1->pontos < t2->pontos)
        return 1;
    else if(t1->pontos == t2->pontos)
        return compara_vitorias(t1, t2);

    return 0;
}

int mesma_pontuacao(Time *t1, Time *t2)
{
    if(t1->saldo == t2->saldo && t1->sofridos == t2->sofridos && t1->marcados == t2->marcados && t1->vitorias == t2->vitorias && t1->pontos == t2->pontos)
        return 1;
    return 0;
}

void apresenta_time(Time *t)
{
    printf("Lider: %s Pontos: %d Vitorias: %d Pro: %d Contra: %d Saldo: %d\n", t->nome,
                                                                                t->pontos,
                                                                                t->vitorias,
                                                                                t->marcados,
                                                                                t->sofridos,
                                                                                t->saldo);
}

void libera_time(Time *t)
{
    free(t->nome);
}

typedef struct
{
    Time t1, t2;
} Jogo;

int le_jogo(Jogo *j)
{
    int comp = 0;
    j->t1 = inicializa_time();
    j->t2 = inicializa_time();

    comp = le_time(&j->t1);
    if(comp < 1)
        return 0;
    if(comp > 0)
    {
        comp = le_time(&j->t2);
        if(comp < 1)
            return 0;
        ponto_dos_times(&j->t1, &j->t2);
    }
    return comp;
}

typedef struct
{
    Time *times;
    int qtd_times,
        max_times;
} Torneio;

Torneio inicializa_torneio()
{
    Torneio t;
    t.qtd_times = 0;
    t.max_times = MAX_JOGOS;
    t.times = (Time *) malloc(sizeof(Time) * t.max_times);

    for(int i = 0; i < t.max_times; i++)
    {
        t.times[i] = inicializa_time();
    }

    return t;
}

void expande_jogo(Torneio *t)
{
    t->max_times += MAX_JOGOS;
    Time *aux = (Time *) malloc(sizeof(Time) * t->max_times);

    for(int i = 0; i < t->qtd_times; i++)
    {
        aux[i] = t->times[i];
    }

    for(int i = t->qtd_times; i < t->max_times; i++)
    {
        aux[i] = inicializa_time();
    }

    free(t->times);
    t->times = aux;
}

void acrescenta_time(Torneio *t, Time *aux)
{
    for(int i = 0; i < t->qtd_times; i++)
    {
        if(times_iguais(&t->times[i], aux))
        {
            modifica_time(&t->times[i], aux);
            return;
        }
    }

    copia_time(&t->times[t->qtd_times++], aux);
}

void le_torneio(Torneio *t)
{
    Jogo aux;
    int test;
    while(le_jogo(&aux))
    {
        if(t->qtd_times == t->max_times)
            expande_jogo(t);

        acrescenta_time(t, &aux.t1);
        acrescenta_time(t, &aux.t2);
        libera_time(&aux.t1);
        libera_time(&aux.t2);
    }
}

void ordena(Torneio *t, int (*cmp)(Time *, Time *))
{
    Time aux;
    for(int i = 0; i < t->qtd_times - 1; i++)
    {
        for(int j = 0; j < t->qtd_times - 1 - j; j++)
        {
            if((*cmp)(&t->times[j], &t->times[j + 1]))
            {
                aux = t->times[j];
                t->times[j] = t->times[j + 1];
                t->times[j + 1] = aux;
            }
        }
    }
}

void apresenta(Torneio *t)
{
    int i = 1;
    if(t->qtd_times >0) {
        apresenta_time(&t->times[0]);
        while (mesma_pontuacao(&t->times[0], &t->times[i])) {
            apresenta_time(&t->times[i]);
            i++;
        }
    }
}

void libera_torneio(Torneio *t)
{
    for(int i = 0; i < t->qtd_times; i++)
    {
        libera_time(&t->times[i]);
    }

    free(t->times);
}

int main()
{
    Torneio torn;

    torn = inicializa_torneio();
    le_torneio(&torn);
    ordena(&torn, compara_pontos);
    apresenta(&torn);
    libera_torneio(&torn);
}