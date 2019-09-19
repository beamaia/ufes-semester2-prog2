#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "data.h"

int nao_tem_aluno(tAluno *a)
{
    return !a->matricula;
}

void leia_aluno(tAluno * aluno)
{
    printf("Matricula: ");
    scanf("%d%*c", &aluno->matricula);

    if(nao_tem_aluno(aluno))
        return;

    printf("Nome: ");
    scanf("%[^\n]", aluno->nome);

    printf("Aniversário: ");
    leia_data(&aluno->niver);

    printf("Ingresso: ");
    leia_data(&aluno->ingresso);
    
    printf("CR: ");
    scanf("%f%*c", &aluno->cr);
}

void imprime_informacoes(tAluno * aluno, FILE * turma)
{
    fwrite("\n\nAluno: ", sizeof(char), 9, turma);
    fwrite(aluno->nome, sizeof(char), 50, turma);
    fwrite("\nMatricula: ", sizeof(char), 12, turma);
    fwrite(&aluno->matricula, sizeof(int), 1, turma);
    fwrite("\nCR: ", sizeof(char), 4, turma);
    fwrite(&aluno->cr, sizeof(float), 1, turma);
    fwrite("\nAniversario: ", sizeof(char), 14, turma);
    //apresenta_data(aluno->niver, turma);
    fwrite("\nIngresso: ", sizeof(char), 14, turma);
    //apresenta_data(aluno->ingresso, turma);
}

int compara_nomes(tAluno *aluno1, tAluno *aluno2)
{
    return strcmp(aluno1->nome, aluno2->nome) > 0;
}

int compara_matriculas(tAluno *aluno1, tAluno *aluno2)
{
    return aluno1->matricula > aluno2->matricula;
}

int compara_cr(tAluno *aluno1, tAluno *aluno2)
{
    return aluno1->cr <= aluno2->cr;
}

int aluno_aniversariante(tData aluno, tData hoje)
{
    return (aluno.dia == hoje.dia && aluno.mes == hoje.mes);
}

int tem_aniversario(tAluno *aluno, tData hoje)
{
    return aluno_aniversariante(aluno->niver, hoje);
}

int aluno_excelente(tAluno *a)
{
    return a->cr >= 8;
}

