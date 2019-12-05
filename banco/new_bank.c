#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int correntista, agencia, banco;
    float operacao;
} Leitura;

void inicializa_leitura(Leitura *l)
{
    l->correntista = l->agencia = l->banco = 0;
    l->operacao = 0;
}

int leitura_banco(Leitura *l)
{
    if(scanf("%d%d%d%f", &l->banco, &l->agencia, &l->correntista, &l->operacao))
        return 1;
    return 0;
}

typedef struct{
    float cred, deb, saldo;
} Operacao;

void adiciona_operacao(Operacao *op, Leitura *l)
{
    if(l->operacao >= 0)
    {
        op->cred += l->operacao;
    }
    else
    {
        op->deb += l->operacao;
    }
    
    op->saldo += l->operacao;
}

int mais_credit(Operacao *op1, Leitura *l)
{
    return op1->cred > l->operacao;
}

int menos_debito(Operacao *op1, Leitura *l)
{
    return op1->deb < l->operacao;
}

int maior_saldo(Operacao *op1, Leitura *l)
{
    return op1->saldo > l->operacao;
}

void coloca_credit(Operacao *op, Leitura *l)
{
    l->operacao = op->cred;
}

void coloca_debito(Operacao *op, Leitura *l)
{
    l->operacao = op->deb;
}

void coloca_saldo(Operacao *op, Leitura *l)
{
    l->operacao = op->saldo;
}

typedef struct{
    int cod;
    Operacao operacao;
} Correntista;


int mesmo_correntista(Correntista *c, Leitura *l)
{
    return c->cod == l->correntista;
}

void coloca_correntista(Correntista *c, Leitura *l, int i)
{
    l->correntista = c->cod;
    switch(i)
    {
        case 1: coloca_credit(&c->operacao, l);
                break;
        case 2: coloca_debito(&c->operacao, l);
                break;
        case 3: coloca_saldo(&c->operacao, l);
                break;
    }
}

typedef struct{
    int cod;
    Correntista *correntistas;
    Operacao op;
    int qtd, qtd_max;
} Agencia;

Agencia inicializa_agencia()
{
    Agencia a;
    a.qtd = 0;
    a.qtd_max = MAX;
    a.correntistas = (Correntista *) malloc(sizeof(Correntista) * a.qtd_max);
    return a;
}

int mesma_agencia(Agencia *a, Leitura *l)
{
   return a->cod == l->agencia;
}

int encontra(Agencia *a, Leitura *l, int (*func(Correntista *, Leitura *)), int escolha)
{
    int mod = 0;
    for(int i = 0; i < a->qtd; i++)
    {
        if((*func)(&a->correntistas[i], l))
        {
            coloca_correntista(&a->correntistas[i], l, escolha);
            mod = 1;
        }
    }
    return mod;
}

int encontra_agencia(Agencia *a, Leitura *l)
{
    int i = 0;
    if(a->cod != l->agencia)
        return 0;

    for(i = 0; i < a->qtd; i++)
    {
        if(mesmo_correntista(&a->correntistas[i], l))
        {
            modifica_correntista(&a->correntistas[i], l);
            break;
        }
    }

    if(a->qtd == a->qtd_max)
        expande_correntista(a);
    if(i == a->qtd)
    {
        a->correntistas[a->qtd] = inicializa_correntista();
        adiciona_correntista(&a->correntistas[a->qtd], l);
        a->qtd++;         
    }
    return 1;
}

void expande_agencia(Agencia *a)
{
    a->qtd_max += MAX;
    Correntista *aux = (Correntista *)malloc(sizeof(Correntista) * a->qtd_max);

    for(int i = 0; i < a->qtd; i++)
    {
        aux[i] = a->correntistas[i];
    }

    free(a->correntistas);
    a->correntistas = aux;
}

void libera_agencia(Agencia *a)
{
    free(a->correntistas);
    free(a);
}

typedef struct{
    int cod;
    Agencia *agencias;
    Operacao operacao;
    int qtd, qtd_max;
} Banco;

Banco inicializa_banco()
{
    Banco b;
    b.qtd = 0;
    b.qtd_max = MAX;
    b.agencias = (Agencia *) malloc(sizeof(Agencia) * b.qtd_max);
    if(b.agencias == NULL)
    {
        printf("Erro na alocação de memória");
        exit(1);
    }
    return b;
}

void expande_banco(Banco *b)
{
    b->qtd_max += MAX;
    Agencia *aux = (Agencia *) malloc(sizeof(Agencia) * b->qtd_max);
    if(aux == NULL)
    {
        printf("Erro na alocação de memória");
        exit(1);
    }

    for(int i = 0; i < b->qtd; i++)
    {
        aux[i] = b->agencias[i];
    }

    free(b->agencias);
    b->agencias = aux;  
}

int encontra_banco(Banco *b, Leitura *l)
{
    if(b->cod != l->banco)
        return 0;
    int i = 0;

    for(i = 0; i < b->qtd; i++)
    {
        if(encontra_agencia(&b->agencias[i], l))
        {
            modifica_agencia(&b->agencias[i], l);
            break;
        }
    }

    if(b->qtd == b->qtd_max)
        expande_banco(b);
    if(i == b->qtd)
    {
        b->agencias[b->qtd] = inicializa_banco();
        adiciona_agencia(&b->agencias[b->qtd], l);
        b->qtd++;         
    }
    return 1;
}

int mesmo_banco(Banco *b, Leitura *l)
{
    return b->cod == l->banco;
}

void adiciona_banco(Banco *b, Leitura *l)
{
    b->qtd = 0;
}

void libera_banco(Banco *b)
{
    for(int i = 0; i < b->qtd; i++)
        libera_agencia(&b->agencias[i]);
    free(b->agencias);
    free(b);
}

typedef struct{
    Banco *bancos;
    int qtd, qtd_max;
} Todos_Bancos;

Todos_Bancos inicializa_todos_bancos()
{
    Todos_Bancos b;
    b.qtd = 0;
    b.qtd_max = MAX;
    b.bancos = (Banco *) malloc(sizeof(Banco) * b.qtd_max);
    return b;
}

void expande_todos_bancos(Todos_Bancos *tb)
{
    tb->qtd_max += MAX;
    Banco *aux = (Banco *) malloc(sizeof(Banco) * tb->qtd_max);
    for(int i = 0; i < tb->qtd; i++)
        aux[i] = tb->bancos[i];

    free(tb->bancos);
    tb->bancos = aux;    
}

void le_todos_bancos(Todos_Bancos *tb)
{
    int i = 0;
    Leitura aux;
    inicializa_leitura(&aux);
    while(leitura_banco(&aux))
    {
        for(i = 0; i < tb->qtd; i++)
        {
            if(encontra_banco(&tb->bancos[i], &aux))
            {
                modifica_banco(&tb->bancos[i], &aux);
                break;
            }
        }

        if(tb->qtd == tb->qtd_max)
            expande_todos_bancos(tb);

        if(i == tb->qtd)
        {
            tb->bancos[tb->qtd] = inicializa_banco();
            adiciona_banco(&tb->bancos[tb->qtd], &aux);
            tb->qtd++;            
        }
    }
}

void libera_todos_bancos(Todos_Bancos *tb)
{
    for(int i = 0; i < tb->qtd; i++)
    {
        libera_banco(&tb->bancos[i]);
    }
    free(tb->bancos);
}

