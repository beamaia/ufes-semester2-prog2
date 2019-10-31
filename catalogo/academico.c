#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academico.h"

struct Academico
{
    char *nome;
    unsigned int idade,
                 matricula;
};

Academico le_nome()
{
    char nome[MAX_NOM];

    Academico a = (Academico) malloc(sizeof(struct Academico));
    scanf("%[^\n]", nome);
    a->nome = (char *) malloc(sizeof(char)*(strlen(nome) + 1));
    strcpy(a->nome, nome);
    
    return a;
}

Academico le_academico()
{
    Academico a = le_nome();
    scanf("%u %u", &a->idade, &a->matricula);

    return a;
}

int comp_nome(Academico a1, Academico a2)
{
    char n1[MAX_NOM], n2[MAX_NOM];
    
    strcpy(n1, a1->nome);
    char *q = n1;
    while(*q++ = toupper(*q));

    strcpy(n2, a2->nome);
    q = n2;
    while(*q++ = toupper(*q));

    while(*q++ = toupper(*q)); 
    if(strcmp(n1, n2) > 0)
        return 1;

    return 0;
}

int comp_matricula(Academico a1, Academico a2)
{
    if(a1->matricula > a2->matricula)   
        return 1;
    return 0;
}

int comp_idade(Academico a1, Academico a2)
{
    if(a1->idade > a2->idade)   
        return 1;
    return 0;  
}

void apresenta_academico(Academico a)
{
    printf("Nome: %s Idade: %u Matricula: %u\n", a->nome,
                                                 a->idade,
                                                 a->matricula);
}

void libera_nome(Academico a)
{
    free(a->nome);
}
void libera_academico(Academico a)
{
    libera_nome(a);
    free(a);
}
