#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 100
#define MAX_NOME 50

//Informacoes sobre data
typedef struct{
    int dia;
    int mes;
    int ano;
} tData;

tData leia_data();
int igualdade_data(tData, tData);
int menor_data(tData, tData);
void apresenta_data(tData);

tData leia_data()
{
    tData data;
    scanf("%d/%d/%d%*c", &data.dia, &data.mes, &data.ano);
    return data;   
}

int igualdade_data(tData data1, tData data2)
{
    return data1.dia == data2.dia && data1.mes == data2.mes;

int menor_data(tData data1, tData data2)
{
    if(data1.ano < data2.ano || 
      (data1.ano == data2.ano && data1.mes < data2.mes) || 
      (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia < data2.dia)) 
    {
        return 1;
    }
    else
        return 0;   
}

void apresenta_data(tData data)
{
    printf("%02d/%02d/%02d",data.dia, data.mes, data.ano);
}

//Informacao sobre alunos
typedef struct{
    int matricula;
    char nome[MAX_NOME];
    float cr;
    tData niver;
    tData ingresso;
    int situacao;
} tAluno;

int leia_matricula();
tAluno leia_aluno();
void imprime_informacoes(tAluno);
int compara_nomes(char [], char []);
int compara_matriculas(int, int);
int compara_cr(int, int);

int leia_matricula()
{
    int matricula;

    printf("Matricula: ");
    scanf("%d", matricula);   

    return matricula;
}

tAluno leia_aluno()
{
    tAluno aluno;

    printf("Nome: ");
    scanf("%[^\n]", aluno.nome);

    printf("CR: ");
    scanf("%f%*c", &aluno.cr);

    printf("Aniversário: ");
    aluno.niver = leia_data();

    printf("Ingresso: ");
    aluno.ingresso = leia_data();

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

int compara_nomes(char nome1[], char nome2[])
{
    if(strcmp(nome1, nome2) < 0) 
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

int aluno_aniversariante(tData aluno)
{
    if(aluno.dia == hoje.dia && aluno.mes == hoje.mes)
        return 1;
    else
        return 0;
}

int aluno_excelente(tAluno a)
{
    return a.cr >= 8;
}