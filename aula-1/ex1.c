#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 100
#define MAX_NOME 50

//Informacao sobre datas
typedef struct{
    int dia;
    int mes;
    int ano;
} tData;

tData leia_data();

//Informacao sobre alunos
typedef struct{
    int matricula;
    char nome[MAX_NOME];
    float cr;
    tData niver;
    tData ingresso;
    int situacao;
} tAluno;

int leia_matricula(tAluno []);

//Funcoes ordenacao
void ordena_nome(tAluno [], int);
void ordena_matricula(tAluno [], int);
void ordena_ingresso(tAluno [], int);
void ordena_cr(tAluno [], int);

//Funcoes de apresentacao
void imprime_informacoes(tAluno);
void apresenta_informacoes(tAluno [], int);
void apresenta_aniversariantes(tAluno [], tData, int);
void apresenta_excelentes(tAluno [], int);

//Funcao para modo
void selecao(tAluno[], int, tData);
int apresenta_pergunta();
void seleciona_modo(tAluno [], int, int, tData);

int main()
{
    tData hoje;
    hoje = leia_data();

    tAluno aluno[MAX_ALUNOS];
    int qtd;

    qtd = leia_matricula(aluno);
    selecao(aluno, qtd, hoje);

    return 0;
}

tData leia_data()
{
    tData hoje;

    scanf("%d/%d/%d", &hoje.dia, &hoje.mes, &hoje.ano);
    return hoje;
}

int leia_matricula(tAluno aluno[])
{
    int num = 0;

    printf("Matricula: ");
    scanf("%d%*c", &aluno[num].matricula);

    for(; num < MAX_ALUNOS && aluno[num].matricula != 0; num++)
    {
        printf("Nome: ");
        scanf("%[^\n]", aluno[num].nome);

        printf("CR: ");
        scanf("%f%*c", &aluno[num].cr);

        printf("Aniversário: ");
        aluno[num].niver = leia_data();

        printf("Ingresso: ");
        aluno[num].ingresso = leia_data();

        printf("Matricula: ");
        scanf("%d%*c", &aluno[num + 1].matricula);     
    }

    return num;
}

void ordena_nome(tAluno aluno[], int qtd_alunos)
{
    tAluno temp;

    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = 0; j < qtd_alunos - 1; j++)
        {
            if(strcmp(aluno[i].nome, aluno[j].nome) < 0) 
            {
                temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
}

void ordena_matricula(tAluno aluno[], int qtd_alunos)
{
    tAluno temp;

    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = 0; j < qtd_alunos - 1; j++)
        {
            if(aluno[i].matricula > aluno[j].matricula) 
            {
                temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
}

void ordena_ingresso(tAluno aluno[], int qtd_alunos)
{
    tAluno temp;

    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = 0; j < qtd_alunos - 1; j++)
        {
            if(aluno[i].ingresso.ano < aluno[j].ingresso.ano || 
              (aluno[i].ingresso.ano == aluno[j].ingresso.ano && aluno[i].ingresso.mes < aluno[j].ingresso.mes) || 
              (aluno[i].ingresso.ano == aluno[j].ingresso.ano && aluno[i].ingresso.mes == aluno[j].ingresso.mes && aluno[i].ingresso.dia < aluno[j].ingresso.dia)) 
            {
                temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }    
}

void ordena_cr(tAluno aluno[], int qtd_alunos)
{
    tAluno temp;

    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = 0; j < qtd_alunos - 1; j++)
        {
            if(aluno[i].cr < aluno[j].cr) 
            {
                temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
}

void imprime_informacoes(tAluno aluno)
{
    printf("Aluno: %s\n", aluno.nome);                                                                        
    printf("Matricula: %d\n", aluno.matricula);
    printf("CR: %.2f\n", aluno.cr);
    printf("Aniversário: %02d/%02d/%02d\n\n", aluno.niver.dia, aluno.niver.mes, aluno.niver.ano);
}

void apresenta_informacoes(tAluno aluno[], int qtd_alunos)
{
    if(!qtd_alunos)
        exit(1);

    for(int i = 0; i < qtd_alunos; i++)
    {
        imprime_informacoes(aluno[i]);
    }
}

void apresenta_aniversariantes(tAluno aluno[], tData hoje, int qtd_alunos)
{
    printf("Aniversariantes: \n\n");

    for(int i = 0; i < qtd_alunos; i++)
    {
        if(hoje.dia == aluno[i].niver.dia && hoje.mes == aluno[i].niver.mes)
            imprime_informacoes(aluno[i]);
    }
}

void apresenta_excelentes(tAluno aluno[], int qtd_aluno)
{   
    for(int i = 0; i < qtd_aluno; i++)
    {
        if(aluno[i].cr >= 8)
            imprime_informacoes(aluno[i]);
    }
}

void selecao(tAluno aluno[], int qtd_aluno, tData hoje)
{
    int entrada;

    entrada = apresenta_pergunta();
    seleciona_modo(aluno, qtd_aluno, entrada, hoje);

}

int apresenta_pergunta()
{
    int entrada; 

    printf("\nEscolha um mode de apresentação:\n");
    printf("1: Todos alunos por ordem de matricula\n");
    printf("2: Todos alunos por ordem alfabetica\n");
    printf("3: Informação dos aniversariantes\n");
    printf("4: Informação dos excelentes\n");
    scanf("%d", &entrada);

    return entrada;
}

void seleciona_modo(tAluno aluno[], int qtd_alunos, int entrada, tData hoje)
{
    switch(entrada)
    {
        case 1: ordena_matricula(aluno, qtd_alunos);
                apresenta_informacoes(aluno, qtd_alunos);
                break;
        case 2: ordena_nome(aluno, qtd_alunos);
                apresenta_informacoes(aluno, qtd_alunos);
                break;
        case 3: ordena_matricula(aluno, qtd_alunos);
                apresenta_aniversariantes(aluno, hoje, qtd_alunos);
                break;
        case 4: ordena_matricula(aluno, qtd_alunos);
                apresenta_excelentes(aluno, qtd_alunos);
                break;
        default: break;
    }
}