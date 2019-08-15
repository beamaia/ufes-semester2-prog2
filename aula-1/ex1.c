#include <stdio.h>
#include <stdlib.h>

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
        scanf("%d", &aluno[num].matricula);

        if(aluno[num].matricula == 0)
            break;

        scanf("%s", &aluno[num].nome);
        scanf("%d", &aluno[num].idade);
        scanf("%d", &aluno[num].notas.p1);
        scanf("%d", &aluno[num].notas.p2);
        scanf("%d", &aluno[num].notas.t1);
        scanf("%d", &aluno[num].notas.t2);
        scanf("%d", &aluno[num].notas.t3);

        aluno[num].media = calcula_media(aluno[num]);
        aluno[num].situacao = situacao_final(aluno[num].media);        
    }
}

float calcula_media(tAluno aluno)
{
    int media;
    media = (aluno.p1 * aluno.t1 + aluno.p2 * aluno.t2)/20 + aluno.t3/10;
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
    char temp;
    qtd_alunos = qtd_matriculas(aluno);

    for(int i = 0; i < qtd_alunos - 1; i++)
    {
        for(int j = 0; j < qtd_alunos - i - 1; j++)
        {
            if(strcmp(aluno[i].nome, aluno[j].nome) < 0) 
            {
                temp = aluno[i].nome;
                aluno[i].nome = aluno[j].nome;
                aluno[j].nome = temp;
            }
    }
}

int qtd_matriculas(tAluno *)
{
    for(int i = 0; aluno[i].matricula == 0; i++);

    return i;
}

void printa_alunos(tAluno *aluno)
{
    for
}