#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "data.h"

int leia_matricula()
{
    int matricula;

    printf("Matricula: ");
    scanf("%d", &matricula);   

    return matricula;
}

tAluno leia_aluno()
{
    tAluno aluno;

    printf("Nome: ");
    scanf("%[^\n]", aluno.nome);

    printf("Aniversário: ");
    aluno.niver = leia_data();

    printf("Ingresso: ");
    aluno.ingresso = leia_data();
    
    printf("CR: ");
    scanf("%f%*c", &aluno.cr);


    return aluno;
}

void imprime_informacoes(tAluno aluno)
{
    printf("\nAluno: %s\n", aluno.nome);                                                                        
    printf("Matricula: %d\n", aluno.matricula);
    printf("CR: %.2f\n", aluno.cr);
    printf("Aniversário: ");
    apresenta_data(aluno.niver);
    printf("\nIngresso: ");
    apresenta_data(aluno.ingresso);
}

int compara_nomes(tAluno aluno1, tAluno aluno2)
{
    if(strcmp(aluno1.nome, aluno2.nome) < 0) 
        return 1;
    else    
        return 0;
}

int compara_matriculas(int matricula1, int matricula2)
{
    if(matricula1 > matricula2) 
        return 1;
    else    
        return 0;
}

int compara_cr(int cr1, int cr2)
{
    if(cr1 <= cr2) 
        return 1;
    else    
        return 0;
}

int aluno_aniversariante(tData aluno, tData hoje)
{
    if(aluno.dia == hoje.dia && aluno.mes == hoje.mes)
        return 1;
    else
        return 0;
}

int tem_aniversario(tAluno aluno, tData hoje)
{
    return aluno_aniversariante(aluno.niver, hoje);
}

int aluno_excelente(tAluno a)
{
    return a.cr >= 8;
}

int nao_tem_aluno(tAluno a)
{
    if(a.matricula == 0)
        return 1;
    return 0;
}