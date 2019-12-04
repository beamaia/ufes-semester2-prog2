#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int **mat;
    int line, col, max_line, max_col;
} matrix;

typedef matrix * Matrix;

Matrix initialize_matrix()
{
    Matrix m = (Matrix) malloc(sizeof(matrix));
    m->line = m->col = 0;
    m->max_line = m->max_col = MAX;
    m->mat = (int **) malloc(sizeof(int *) * m->max_line);
    for(int i = 0; i < m->max_line; i++)
    {
        m->mat[i] = (int *) malloc(sizeof(int) * m->max_col);
    }

    return m;   
}

void expand_line(Matrix m)
{
    m->max_line += MAX;
    int **aux = (int **)malloc(sizeof(int *) * m->max_line);
    for(int i = 0; i < m->line; i++)
    {
        aux[i] = m->mat[i];
    } 

    for(int i = m->line; i < m->max_line; i++)
    {
        aux[i] = (int *)malloc(sizeof(int) * m->max_col);
    }

    free(m->mat);
    m->mat = aux;
}

void expand_column(Matrix m)
{
    m->max_col += MAX;
    int **aux = (int **)malloc(sizeof(int *) * m->max_line);

    for(int i = 0; i < m->line; i++)
    {
        aux[i] = (int *)malloc(sizeof(int) * m->max_col);
        for(int j = 0; j < m->col; j++)
        {
            aux[i][j] = m->mat[i][j];
        }
    }

    for(int i = m->line; i < m->max_line; i++)
    {
        aux[i] = (int *) malloc(sizeof(int) * m->max_col);
    }

    for (int i = 0; i < m->max_line; i++)
    {
        free(m->mat[i]);
    }

    free(m->mat);
    m->mat = aux;
}

void read_matrix(Matrix m)
{
    int aux, j = 0;
    char enter;

    while(scanf("%d%c", &aux, &enter) == 2)
    {
        if(m->line == m->max_line)
            expand_line(m);
        if(m->col == m->max_col)
            expand_column(m);

        m->mat[m->line][j % m->col] = aux;

        if(enter == '\n')
        {
            m->line++;
            j++;
            if(m->line == 1)
                m->col = j;
        }
        else if(enter == ' ')
            j++;
    }
}

int main()
{
    Matrix m = initialize_matrix();
    read_matrix(m);
    printf("%d %d", m->col, m->line);
    return 0;
}
