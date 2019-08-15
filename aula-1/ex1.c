#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float p1;
    float p2;
    float t1;
    float t2;
    float t3;
} tNotas;

typedef struct{
    int matricula;
    char nome[16];
    int idade;
    tNotas notas;
    float media;
    int situacao;
} tAluno;

void leia_matricula(tAluno*);
float calcula_media(tAluno);
int situacao_final(float);
void ordena_matriculas(tAluno *);
int qtd_matriculas(tAluno *);
void printa_alunos(tAluno *);


int main()
{
    tAluno aluno[40];

    leia_matricula(aluno);
    ordena_matriculas(aluno);
    printa_alunos(aluno);

    return 0;
}

void leia_matricula(tAluno *aluno)
{
    for(int num = 0; num < 40; num++)
    {
        printf("Matricula: ");
        scanf("%d", &aluno[num].matricula);

        if(aluno[num].matricula == 0)
            break;

        printf("Nome: ");
        scanf("%s", aluno[num].nome);

        printf("Idade: ");
        scanf("%d", &aluno[num].idade);

        printf("Nota P1: ");
        scanf("%f", &aluno[num].notas.p1);

        printf("Nota P2: ");
        scanf("%f", &aluno[num].notas.p2);

        printf("Nota T1: ");
        scanf("%f", &aluno[num].notas.t1);

        printf("Nota T2: ");
        scanf("%f", &aluno[num].notas.t2);

        printf("Nota T3: ");
        scanf("%f", &aluno[num].notas.t3);

        aluno[num].media = calcula_media(aluno[num]);
        aluno[num].situacao = situacao_final(aluno[num].media);        
    }
}

float calcula_media(tAluno aluno)
{
    float media;
    media = ((aluno.notas.p1 * aluno.notas.t1) + (aluno.notas.p2 * aluno.notas.t2))/20 + aluno.notas.t3/10;
    return media;
}

int situacao_final(float media)
{
    if(media >= 7)
        return 1;
    else
        return 0;
}

void ordena_matriculas(tAluno * aluno)
{
    int qtd_alunos;
    tAluno temp;
    char nome_temp[16];
    qtd_alunos = qtd_matriculas(aluno);
    
    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = i; j < qtd_alunos; j++)
        {
            if(strcmp(aluno[i].nome, aluno[j].nome) > 0) 
            {
                temp = aluno[j];
                aluno[j] = aluno[i];
                aluno[i] = temp;
                printf("%s %s\n\n", aluno[i].nome, aluno[j].nome);
            }
        }
    }
}

int qtd_matriculas(tAluno * aluno)
{
    int i;
    for(i = 1; ; i++)
    {
        if(aluno[i].matricula == 0)
            break;
    }
    return i;
}

void printa_alunos(tAluno *aluno)
{
    int qtd_alunos = qtd_matriculas(aluno);

    if(qtd_alunos == 0)
        exit(1);

    for(int i = 0; i < qtd_alunos; i++)
    {
        printf("\nAluno: %s\nMatricula: %d\nIdade: %d\nMedia Parcial: %.2f\nPrecisa de prova final?: ", aluno[i].nome, aluno[i].matricula, aluno[i].idade, aluno[i].media);

        if(aluno[i].situacao == 1)
            printf("Não \n");
        else
            printf("Sim \n");
    }
}