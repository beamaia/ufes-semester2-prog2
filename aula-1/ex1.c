#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 40

//Imprima a lista de aniversariante ordenado por matricula

typedef struct{
    float p1;
    float p2;
    float t1;
    float t2;
    float t3;
    float media;
} tNotas;

typedef struct{
    int dia;
    int mes;
    int ano;
} tAniversario;

typedef struct{
    int dia;
    int mes;
    int ano;
} tIngresso;

typedef struct{
    int matricula;
    char nome[50];
    tNotas notas;
    tAniversario niver;
    tIngresso ingresso;
    int situacao;
} tAluno;

int leia_matricula(tAluno*);
float calcula_media(tAluno);
int situacao_final(float);
void ordena_matriculas(tAluno *, int);
void printa_alunos(tAluno *, int);

int main()
{
    tAluno aluno[TAM];
    int qtd;

    qtd = leia_matricula(aluno);
    ordena_matriculas(aluno, qtd);
    printa_alunos(aluno, qtd);

    return 0;
}

int leia_matricula(tAluno *aluno)
{
    int num;
    for(num = 0; ; num++)
    {
        printf("Nome: ");
        scanf("%[^\n]", aluno[num].nome);

        printf("Matricula: ");
        scanf("%d", &aluno[num].matricula);

        if(aluno[num].matricula == 0)
            break;

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

        printf("Aniversário: ");
        scanf("%d/%d/%d", &aluno[num].niver.dia, &aluno[num].niver.mes, &aluno[num].niver.ano);

        printf("Ingresso: ");
        scanf("%d/%d/%d%*c", &aluno[num].ingresso.dia, &aluno[num].ingresso.mes, &aluno[num].ingresso.ano);

        aluno[num].notas.media = calcula_media(aluno[num]);
        aluno[num].situacao = situacao_final(aluno[num].notas.media);        
    }

    return num;
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

void ordena_matriculas(tAluno * aluno, int qtd_alunos)
{
    tAluno temp;
    char nome_temp[16];

    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = i; j < qtd_alunos; j++)
        {
            if(strcmp(aluno[i].nome, aluno[j].nome) > 0) 
            {
                temp = aluno[j];
                aluno[j] = aluno[i];
                aluno[i] = temp;
            }
        }
    }
}

void printa_alunos(tAluno *aluno, int qtd_alunos)
{
    if(qtd_alunos == 0)
        exit(1);

    for(int i = 0; i < qtd_alunos; i++)
    {
        printf("\nAluno: %s\nMedia Parcial: %.2f\nPrecisa de prova final?: ", aluno[i].nome, aluno[i].notas.media);

        if(aluno[i].situacao == 1)
            printf("Não \n");
        else
            printf("Sim \n");
    }
}

