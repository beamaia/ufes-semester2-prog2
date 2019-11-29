#include <stdio.h>
#include <stdlib.h>
#define MAX_QT 50

typedef struct{
    unsigned int bank, agency, person;
    float operation;
} tAux;

typedef tAux * Aux;

Aux initialize_aux()
{
    Aux a;
    a = (Aux) malloc(sizeof(tAux));
    a->bank = a->agency = a->person = 0;
    a->operation = 0;
    return a;
}

int read_aux(Aux a)
{
    int nc;
    nc = scanf("%u%u%u%f", &a->bank, &a->agency, &a->person, &a->operation);
    return nc;
}

void free_aux(Aux a)
{
    free(a);
}

typedef struct{
    float cred;
    float debt;
    float total;
} Operacao;

void inicializa_operacao(Operacao *op)
{
    op->debt = op->cred = op->total = 0;
}

void altera_operacao(Operacao *op, Aux a)
{
    if(a->operation > 0 || a->operation == 0)
        op->cred += a->operation;
    else
        op->debt += a->operation;
    op->total = op->debt + op->cred;
}

typedef struct{
    int conta;
    Operacao op;
} correntista;

typedef correntista * Correntista;

Correntista inicializa_correntista()
{
    Correntista c;
    c = (Correntista) malloc(sizeof(correntista));
    inicializa_operacao(&c->op);
}

int mesmo_correntista(Correntista co, Aux a)
{
    return co->conta == a->person;
}

void altera_correntista(Correntista co, Aux a)
{
    altera_operacao(&co->op, a);
}

typedef struct{
    unsigned int agencia;
    Correntista *correntist;
    int qtd;
    int qtd_max;
} agencia;

typedef agencia * Agencia;

Agencia inicializa_agencia(Aux op)
{
    Agencia a;
    a = (Agencia) malloc(sizeof(agencia));
    a->qtd_max = MAX_QT;
    a->qtd = 1;
    a->correntist = (Correntista *) malloc(sizeof(Correntista) * a->qtd_max);
    a->correntist[0] = inicializa_correntista();
    altera_correntista(a->correntist[0], op);
}

void expande_agencia(Agencia a)
{
    Correntista *ax;
    a->qtd_max += MAX_QT;
    ax = (Correntista *) malloc(sizeof(Correntista) * a->qtd_max);
    for(int i = 0; i < a->qtd; i++)
    {
        ax[i] = a->correntist[i];
    }
    free(a->correntist);
    a->correntist = ax;
}

int mesma_agencia(Agencia a, Aux ax)
{
    return a->agencia == ax->agency;
}

void encontra_conta(Agencia a, Aux ax)
{
    for(int i = 0; i < a->qtd; i++)
    {

    }
}

void libera_agencia(Agencia a)
{
    for(int i = 0; i < a->qtd; i++)
    {
        free(a->correntist[i]);
    }
    free(a->correntist);
    free(a);
}


int main()
{
    Aux a = initialize_aux();

    while(read_aux(a))
    {

    }

    return 0;
}