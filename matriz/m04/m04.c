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

    for(int i = 0; i < m->max_lin; i++)
    {
        free(m->matriz[i]);
    }
    free(m->matriz);
    return aux;
}

Matriz le_matriz(Matriz *m)
{
    int aux = 0;
    char esp;
    int j = 0, i = 0;

    while(scanf("%d%c", &aux, &esp) == 2)
    {
        if(i == m->max_lin - 1)
            *m = expande_matriz(m);
        if(j == m->max_col - 1)
            *m = expande_matriz(m);

        if(i == 0)
            m->col++;

        m->matriz[i][j] = aux;
        j++;

        if(esp == '\n')
        {
            i++;
            m->lin++;
            j = 0;
        }
    }

    return *m;
}

void ver_se_isolado(Matriz m) {
    int qtd = 0, c = -1, d = -1, p = 0, cont = 0;

    for (int i = 0; i < m.lin; i++) {
        for (int j = 0; j < m.col; j++) {
            if (m.matriz[i][j] == 0)
                continue;
            else if (m.matriz[i][j] == 1) {
                while(1)
                {
                    switch (p) {
                        case 0:
                            d = -1;
                            c = -1;
                            p++;
                            break;
                        case 1:
                            d = -1;
                            c = 0;
                            p++;
                            break;
                        case 2:
                            d = -1;
                            c = 1;
                            p++;
                            break;
                        case 3:
                            d = 0;
                            c = -1;
                            p++;
                            break;
                        case 4:
                            d = 0;
                            c = 1;
                            p++;
                            break;
                        case 5:
                            d = 1;
                            c = -1;
                            p++;
                            break;
                        case 6:
                            d = 1;
                            c = 0;
                            p++;
                            break;
                        case 7:
                            d = 1;
                            c = 1;
                            p++;
                            break;
                    }

                    if(i == m.col - 1 && j == m.lin - 1)
                        break;

                    if((i == 0 && c < 0) || (i == m.lin - 1 && c > 0))
                        continue;

                    if((j == 0 && d < 0) || (j == m.col - 1 && d > 0))
                        continue;

                    if(m.matriz[i + 1 * c][j + 1 * d] == 0)
                        cont++;
                    else if(p == 7 || m.matriz[i + 1 * c][j + 1 * d] == 1)
                        break;

                }
            }

            if (cont == 8)
                qtd++;
        }
    }

}

int main()
{
    Matriz m;
    m.max_col = m.max_lin = MAX_TAM;
    m.col = m.lin = 1;
    m = inicializa_matriz(m);
    m = le_matriz(&m);
    ver_se_isolado(m);
    libera_matriz(&m);

    return 0;
}