#include <stdio.h>
#define max_alunos 100
#define max_cursos 30

typedef struct{
    int matricula;
    float cr;
} aluno;

void le_aluno(aluno * a, FILE * fp)
{
    fscanf(fp, "%d %f", &a->matricula, &a->cr);
}

int compara_matricula(aluno * a1, aluno * a2)
{
    return a1 >= a2; 
}

void imprime_aluno(aluno a, FILE * fp)
{
    fprintf(fp, "Matricula: %d, CR: %.2f\n", a.matricula, a.cr);
}

typedef struct{
    aluno turma[max_alunos];
    int qtd_alunos;
} alunos;

void le_alunos(alunos * c, FILE * fp)
{
    le_aluno(&c->turma[c->qtd_alunos -1], fp);
}

void apresenta_alunos(alunos * a, FILE *fp)
{
    for(int i = 0; i < a->qtd_alunos; i++)
    {
        imprime_aluno(a->turma[i], fp);
    }
}


void ordena_alunos(alunos * a, int (*compara)(aluno *, aluno *))
{
    aluno aux;
    for(int i = 0; i < a->qtd_alunos - 1; i++)
    {
        for(int j = 0; j < a->qtd_alunos - i - 1; j++)
        {
            if((*compara)(&a->turma[j], &a->turma[j + 1]))
            {
                aux = a->turma[j];
                a->turma[j] = a->turma[j + 1];
                a->turma[j + 1] = aux;
            }
        }
    }
}

void zera_qtd(alunos * a)
{
    a->qtd_alunos = 0;
}

typedef struct{
    alunos curso[max_cursos];
    int qtd_cursos;
    int cod_curso[max_cursos];
} curso;

void le_cod_curso(int * aux, FILE * fp)
{
    fscanf(fp, "%d", aux);
}

int verifica_cod(int c, int cod)
{
    return cod == c;
}

void zera_qtd_alunos(curso * c)
{
    for(int i = 0; i < 30; i++)
    {
        zera_qtd(&c->curso[i]);
    }
}


void identifica_cod(int * cod_curso, curso * c, FILE * fp)
{
    for(int j = 0; j < c->qtd_cursos; j++)
    {
        if(verifica_cod(*cod_curso, c->cod_curso[j]))
        {
            le_alunos(&c->curso[j], fp); 
        }
    }
}

void le_curso(curso * c, FILE * fp)
{
    c->qtd_cursos = 0;
    int i = 0;
    int aux = 0;
    zera_qtd_alunos(c);
    while(feof(fp) == 0)
    {
        le_cod_curso(&aux, fp);
        i++;
        c->qtd_cursos = i;
        identifica_cod(&aux, c, fp);
    }
}

void ordena_cursos(curso * c)
{
    alunos aux;
    int temp;
    for(int i = 0; i < c->qtd_cursos - 1; i++)
    {
        for(int j = 0; j < c->qtd_cursos - i - 1; j++)
        {
            if(c->cod_curso[j] >= c->cod_curso[j + 1])
            {
                aux = c->curso[j];
                temp = c->cod_curso[j];
                c->curso[j] = c->curso[j + 1];
                c->cod_curso[j] = c->cod_curso[j + 1];
                c->curso[j + 1] = aux;
                c->cod_curso[j + 1] = temp;
                ordena_alunos(c->curso, compara_matricula);
            }
        }

    }  
}

void apresenta_cursos(curso c, FILE * fp)
{
    for(int i = 0; i < c.qtd_cursos; i++)
    {
        fprintf(fp, "Curso: %d\n", c.cod_curso[i]);
        apresenta_alunos(&c.curso[i], fp);
        fprintf(fp, "\n");
    }
}

int main()
{
    curso uni;
    FILE * fp = fopen("entrada.txt", "r");
    le_curso(&uni, fp);
    ordena_cursos(&uni);
    apresenta_cursos(uni, fp);
    fclose(fp);
    return 0;
}