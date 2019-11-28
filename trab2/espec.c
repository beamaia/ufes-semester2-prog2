#include <stdlib.h>
#include <stdio.h>
#include "espec.h"

/*
Informacoes do arquivo espec.txt como a porcentagem de imoveis caros da lista a,
a porcentagem de terrenos argilosos da lista b e a área e o preço limite das casas
que irão compor a lista c, além da posicao dos identificadores que devem ser somados
(i, j, k) no final do programa.
*/

struct espec
{
    unsigned int percent_caros,
                 percent_argiloso,
                 i,
                 j,
                 k;
    float area_limite,
          preco_limite;
};

Espec inicializa_espec()
{
    Espec esp = (Espec) malloc(sizeof(struct espec));
    esp->percent_caros = 0;
    esp->percent_argiloso = 0;
    esp->i = 0;
    esp->j = 0;
    esp->k = 0;
    esp->area_limite = 0;
    esp->preco_limite = 0;
    return esp;
}

//Leitura dos dados do arquivo espec.txt.
void le_espec(Espec esp, FILE * arq)
{
    fscanf(arq, "%u", &esp->percent_caros);
    fscanf(arq, "%u", &esp->percent_argiloso);
    fscanf(arq, "%f", &esp->area_limite);
    fscanf(arq, "%f", &esp->preco_limite);
    fscanf(arq, "%u%u%u", &esp->i,
                            &esp->j,
                            &esp->k);
}

unsigned int calcula_qtd_cara_espec(Espec esp, unsigned int qtd)
{
    return esp->percent_caros * qtd / 100;
}

unsigned int calcula_qtd_argilosos_espec(Espec esp, unsigned int qtd)
{
    return esp->percent_argiloso * qtd / 100;
}


int espec_id_limite(Espec esp, int escolha, unsigned int limite)
{
    switch(escolha)
    {
        case 1: return esp->i > limite;
        case 2: return esp->j > limite;
        case 3: return esp->k > limite;
        default: return 0;
    }
}

int espec_id_zerado(Espec esp, int escolha)
{
    switch(escolha)
    {
        case 1: return esp->i == 0;
        case 2: return esp->j == 0;
        case 3: return esp->k == 0;
        default: return 0;
    }
}

int get_espec_letra(Espec esp, int escolha)
{
    switch(escolha)
    {
        case 1: return esp->i;
        case 2: return esp->j;
        case 3: return esp->k;
        default: return 0;
    }
}

void libera_espec(Espec esp)
{
    free(esp);
}

// Identificadores referente as posicoes i, j e k estabelecidas pelo arquivo espec.txt
struct identificadores
{
    unsigned int i, j, k;
};

//Iguala todos identificadores a 0;
Identificadores inicializa_identificadores()
{
    Identificadores  id = (Identificadores) malloc(sizeof(struct identificadores));
    id->i = 0;
    id->j = 0;
    id->k = 0;
}

int espec_imovel_limite(float area, float preco, Espec espec)
{
    if(area > espec->area_limite && preco < espec->preco_limite)
        return 1;

    return 0;   
}

void zera_id(Identificadores id, int escolha)
{
    switch(escolha)
    {
        case 1: id->i = 0;
                break;
        case 2: id->j = 0;
                break;
        case 3: id->k = 0;
                break;
        default: return;
    }
}

void atribui_valor_id(Identificadores id, unsigned int valor, int escolha)
{
    switch(escolha)
    {
        case 1: id->i = valor;
                break;
        case 2: id->j = valor;
                break;
        case 3: id->k = valor;
                break;
        default: return;
    }
}
void imprime_soma_id(Identificadores id)
{
    printf("%d\n", id->i + id->j + id->k);
}

void libera_id(Identificadores id)
{
    free(id);
}
