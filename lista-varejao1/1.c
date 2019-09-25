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
    le_aluno(c->turma[c->qtd_alunos -1], fp);
}

void apresenta_alunos(alunos * a, FILE *fp)
{
    for(int i = 0; i < a->qtd_alunos; i++)
    {
        imprime_aluno(a->turma[i], fp);
    }
}

typedef struct{
    alunos curso[max_cursos];
    int qtd_cursos;
    int cod_curso[max_cursos];
} curso;

void le_cod_curso(int * aux, FILE * fp)
{
    fscanf(fp, "%d", &aux);
}

int verifica_cod(int c, int cod)
{
    return cod == c;
}

void identifica_cod(int * cod_curso, curso * c, int i, FILE * fp)
{
    if(verifica(cod_curso, c->cod_curso[i]))
    {
        le_alunos(c->curso[i], fp); 
    }
}

void le_curso(curso * c, FILE * fp)
{
    c->qtd_cursos = 0;
    int aux = 0;
    while(feop(fp) == 0)
    {
        le_cod_curso(&aux, fp);
    }
}

int main()
{

}