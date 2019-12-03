#include <stdio.h>
#include <stdlib.h>
#define MAX_QT 50

typedef struct{
    unsigned int bank, agency, person;
    float operation;
} Aux;

int read_aux(Aux *a)
{
    int nc;
    nc = scanf("%u%u%u%f", &a->bank, &a->agency, &a->person, &a->operation);
    return nc;
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

void altera_operacao(Operacao *op, Aux *a)
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

int mesmo_correntista(Correntista co, Aux *a)
{
    return co->conta == a->person;
}

void altera_correntista(Correntista co, Aux *a)
{
    altera_operacao(co->op, a);
}

void cria_correntista(Correntista co, Aux *a)
{
    co->conta = a->person;
    altera_correntista(co, a);
}

typedef struct{
    unsigned int agencia;
    Correntista *correntist;
    int qtd;
    int qtd_max;
    Operacao op;
} agencia;

typedef agencia * Agencia;

Agencia inicializa_agencia(Aux *op)
{
    Agencia a;
    a = (Agencia) malloc(sizeof(agencia));
    a->qtd_max = MAX_QT;
    a->qtd = 1;
    a->correntist = (Correntista *) malloc(sizeof(Correntista) * a->qtd_max);
    a->correntist[0] = inicializa_correntista();
    altera_correntista(a->correntist[0], op);
    return a;
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

int mesma_agencia(agencia *a, Aux *ax)
{
    return a->agencia == ax->agency;
}

void adiciona_correntista(Agencia a, Aux *ax)
{
    Correntista c = inicializa_correntista();
    cria_correntista(c,ax);
    a->correntist[a->qtd++] = c;
}

void encontra_conta(Agencia a, Aux *ax)
{
    for(int i = 0; i < a->qtd; i++)
    {
        if(mesmo_correntista(a->correntist[i], ax))
        {
            altera_correntista(a->correntist[i], ax);
            return;
        }
    }

    if(a->qtd == a->qtd_max)
        expande_agencia(a);

    adiciona_correntista(a, ax);
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

typedef struct{
    Agencia *agencia;
    int qtd, qtd_max;
    Operacao op;
    int banco;
} banco;

typedef banco * Banco;

int mesmo_banco(Banco b, Aux *a)
{
    return b->banco == a->bank;
}

void adiciona_agencia(Banco b, Aux *ax)
{
    b->agencia[b->qtd++] = inicializa_agencia(ax);
}

void encontra_banco(Banco b, Aux *a)
{
    for(int i = 0; i < b->qtd; i++)
    {
        if(mesma_agencia(b->agencia, a))
        {
            encontra_conta(b->agencia[i], a);
            return;
        }
    }

    adiciona_agencia(b, a);
}

void adiciona_banco(Banco b, Aux *op)
{
    adiciona_agencia(b, op);
}

void libera_banco(Banco a)
{
    for(int i = 0; i < a->qtd; i++)
    {
        libera_agencia(a->agencia[i]);
    }
    free(a->agencia);
    free(a);
}

typedef struct{
    Banco *bancos;
    int qtd, qtd_max;
    Operacao op;
} bancos;

typedef bancos * Bancos;

Bancos inicializa_bancos()
{
    Bancos b = (Bancos) malloc(sizeof(bancos));
    b->qtd = 0;
    b->qtd_max = MAX_QT;
    b->bancos = (Bancos *) malloc(sizeof(Banco) * b->qtd_max); 
    return b;
}


void encontra_catalogo(Bancos b, Aux *ax)
{
    for(int i = 0; i < b->qtd; i++)
    {
        encontra_banco(b->bancos[i], ax);
        return;
    }

    adiciona_banco(b, ax);
}

int main()
{
    Aux a;
    Bancos b;
    while(read_aux(&a))
    {
        encontra_catalogo(b, &a);
    }

    return 0;
}