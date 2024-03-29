#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 10

typedef struct{
    int **matriz;
    int col;
    int lin;
    int max_col;
    int max_lin;
} Matriz;


Matriz inicializa_matriz(Matriz x)
{
    x.matriz = (int **) malloc(sizeof(int *) * x.max_lin);

    for(int i = 0; i < x.max_lin; i++)
    {
        x.matriz[i] = (int *) malloc(sizeof(int) * x.max_col);
        for(int j = 0; j < x.max_col; j++)
        {
            x.matriz[i][j] = 0;
        }
    }

    return x;
}

void libera_matriz(Matriz *m)
{
    for(int i = 0; i < m->max_lin; i++)
    {
        free(m->matriz[i]);
    }

    free(m->matriz);
}

Matriz expande_matriz(Matriz *m)
{
    Matriz aux;
    aux.max_col = m->max_col + MAX_TAM;
    aux.max_lin = m->max_lin + MAX_TAM;
    aux.lin = m->lin;
    aux.col = m->col;

    aux = inicializa_matriz(aux);

    for(int i = 0; i < aux.lin; i++)
    {
        for(int j = 0; j< aux.col; j++)
        {
            aux.matriz[i][j] = m->matriz[i][j];
        }
    }

    libera_matriz(m);
    return aux;
}

Matriz le_matriz(Matriz *m)
{
    int aux = 0;
    char esp;
    int j = 0, i = 0;

    while(scanf("%d%c", &aux, &esp) == 2)
    {
        if(i == m->max_lin - 1) // Quando i == m->max_lin estava ocorrendo segfault com testes em que i > j e i > m->max_lin 
            *m = expande_matriz(m);
        if(j == m->max_col - 1) //Nao estava tendo o problemo que o primeiro if estava tendo
            *m = expande_matriz(m);

        if(i == 0)  //Conta a quantidade de colunas enquanto le a primeira linha
            m->col++;

        m->matriz[i][j] = aux; 
        j++; //Muda de coluna

        if(esp == '\n') //Quando lê '\n' ele muda para a próxima linha;
        {
            i++;
            m->lin++; //Aumenta a quantidade de linhas da matriz
            j = 0; //Volta para coluna = 0
        }
    }

    return *m;
}

void apresenta_matriz(Matriz m)
{
    for(int i = 0; i < m.col - 1; i++)
    {
        for(int j = 0; j < m.lin - 1; j++)
        {
                printf("%d ", m.matriz[j][i]);           
        }
        printf("\n");
    }
}

int main()
{
    Matriz m;
    m.max_col = MAX_TAM;
    m.max_lin = MAX_TAM;
    m.col = m.lin = 1;
    m = inicializa_matriz(m);
    m = le_matriz(&m);
    apresenta_matriz(m);
    libera_matriz(&m);

    return 0;
}