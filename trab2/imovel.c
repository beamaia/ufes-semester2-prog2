#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espec.h"
#include "categoria.h"
#include "imovel.h"
#define MAX_NOME 41

/*
Dados do imovel. O tag do tipo de imovel, o nome do proprietario, o codigo de identificacao,
as informacoes do imovel de acordo com seu tipo, o preco total e a area total construida.
*/
struct imovel 
{
    char * tipo_imovel,
         * nome_proprietario;
    unsigned int id;
    Categoria categoria;
    float preco,
          area;
};

/*
Identifica qual e a categoria escolhida:
1: Triangulo
2: Retangulo
3: Trapezio
4: Casa
5: Apartamento
*/

int identifica_categoria(Imovel imo)
{
    if(!strcmp(imo->tipo_imovel, "triang"))
        return 1;
    if(!strcmp(imo->tipo_imovel, "retang"))
        return 2;
    if(!strcmp(imo->tipo_imovel, "trapez"))
        return 3;
    if(!strcmp(imo->tipo_imovel, "casa"))
        return 4;
    if(!strcmp(imo->tipo_imovel, "apto"))
        return 5;
    return 0;
}

Imovel inicializa_imoveis()
{
    Imovel imo;

    imo = (Imovel) malloc(sizeof(struct imovel));

    if(imo == NULL)
    {
        printf("Erro na alocação de memoria, abortando programa");
        exit(1);
    }

    imo->area = 0;
    imo->id = 0;
    imo->preco = 0;
    return imo;
}

char * le_tipo_imovel(FILE *arq)
{
    char *tipo;
    char aux[7];
    fscanf(arq, "%s\n", aux);

    tipo = (char *) malloc(sizeof(char) * (strlen(aux) + 1));
    if(tipo == NULL)
    {
        printf("Erro na alocação de memoria, abortando programa");
        exit(1);
    }

    strcpy(tipo, aux);
    return tipo;
}

//Le uma linha de apenas caracteres
char * le_nome_proprietario(FILE *arq)
{
    char *nome;
    char aux[MAX_NOME];
    fscanf(arq, "%[^\n]\n", aux);

    nome = (char *) malloc(sizeof(char) * (strlen(aux) + 1));
    if(nome == NULL)
    {
        printf("Erro na alocação de memoria, abortando programa");
        exit(1);
    }

    strcpy(nome, aux);
    return nome;
}

//Leitura dos dados do imovel. Retorna 1 caso foi feito a leitura de um imovel, 0 caso o contrario.
int le_imovel(Imovel imo, FILE *arq)
{
    imo->tipo_imovel = le_tipo_imovel(arq);
    fscanf(arq, "%u\n", &imo->id);
    imo->nome_proprietario = le_nome_proprietario(arq);
    
    int cat = identifica_categoria(imo);
    imo->categoria = inicializa_categoria(cat);
    return le_categoria(imo->categoria, cat, arq);
}

//Iguala as informacoes do imovel imo1 ao do imovel imo2.
void modifica_imovel(Imovel imo1, Imovel imo2)
{
    strcpy(imo1->tipo_imovel, imo2->tipo_imovel);
    strcpy(imo1->nome_proprietario, imo2->nome_proprietario);
    imo1->id = imo2->id;
    imo1->categoria = imo2->categoria;
    imo1->preco = imo2->preco;
    imo1->area = imo2->area;
    imo1->preco = imo2->preco;
    imo1->area = imo2->area;
}

void modifica_imovel_inclusao(Imovel imo1, Imovel imo2)
{
    imo1->tipo_imovel = (char *) malloc(sizeof(char) * (strlen(imo2->tipo_imovel) + 1));
    strcpy(imo1->tipo_imovel, imo2->tipo_imovel);
    imo1->nome_proprietario = (char *) malloc(sizeof(char) * (strlen(imo2->nome_proprietario) + 1));
    strcpy(imo1->nome_proprietario, imo2->nome_proprietario);
    imo1->id = imo2->id;
    imo1->categoria = inicializa_categoria(identifica_categoria(imo1));
    imo1->categoria = imo2->categoria;
    imo1->preco = imo2->preco;
    imo1->area = imo2->area;
    imo1->preco = imo2->preco;
    imo1->area = imo2->area;
}

void modifica_imovel_alteracao(Imovel imo1, Imovel imo2)
{
//    libera_imovel(imo1);
//    imo1 = (Imovel) malloc(sizeof(struct imovel));
    modifica_imovel_inclusao(imo1, imo2);

}

//Chama a funcao que retorna o preco total to imovel e armazena o valor dentro do struct tImovel.
void preco_imovel(Imovel imo)
{
    imo->preco = categoria_preco_imovel(imo->categoria, identifica_categoria(imo));
}

//Chama a funcao que retorna a area total construida to imovel e armazena o valor dentro do struct tImovel.
void area_imovel(Imovel imo)
{
    imo->area = categoria_area_imovel(imo->categoria, identifica_categoria(imo));
}

//Verifica se a cara esta dentro do limite de area e preco de acordo com as informacoes do arquivo espec.txt.
int imovel_limite_area_preco(Imovel imo, Espec espec)
{
    return espec_imovel_limite(imo->area, imo->preco, espec);
}

//Verifica se o numero de identificacao de imoveis diferentes sao iguais.
int compara_id(Imovel imo1, Imovel imo2)
{
    return imo1->id == imo2->id;
}

//Associa um numero de identificacao id a um imovel imo.
void acrescenta_id(Imovel imo, unsigned int id)
{
    imo->id = id;
}

/*
Compara a quantidade de quartos de dois imoveis, retorna 1 caso o imovel imo1
tenha menos quartos ou se tem a mesma quantidade, porem o identificador do 
imovel imo1 seja menor que o do imovel imo2. Retorna 0 caso o imovel imo2 tenha
menos quartos.
*/
int compara_quartos(Imovel imo1, Imovel imo2)
{
    int situacao = categoria_compara_quartos(imo1->categoria, imo2->categoria);
    if(situacao == 1 || (situacao == 2 && imo1->id < imo2->id))
        return 1;

    return 0;
}

/*
Compara o preco de dois imoveis e retorna 1 caso o imovel imo1 seja mais caro ou
se os imoveis apresentam o mesmo preco, porem o identificador do imovel imo1 seja
maior que o imovel imo2. Retorna 0 caso o imovel imo2 seja mais caro.
*/
int compara_preco(Imovel imo1, Imovel imo2)
{
    if(imo1->preco > imo2->preco || (imo1->preco == imo2->preco && imo1->id > imo2->id))
    {
        return 1;
    }

    return 0;
}

/*
Compara a area construida de dois imoveis e retorna 1 caso o imovel imo1 seja menor 
ou se os imoveis apresentam a mesma area, porem o identificador do imovel imo1 seja
maior que o imovel imo2. Retorna 0 caso o imovel imo2 seja menor.
*/
int compara_area(Imovel imo1, Imovel imo2)
{
    if(imo1->area < imo2->area || (imo1->area == imo2->area && imo1->id > imo2->id))
        return 1;
        
    return 0;
}

//Retorna o numero de identificacao do imovel.
unsigned int identifica_id(Imovel imo)
{
    return imo->id;
}

//Chama a funcao que verifica se o imovel tem um solo argiloso.
int imovel_identifica_argiloso(Imovel imo)
{
    int tipo_imovel = identifica_categoria(imo);
    if(categoria_identifica_argiloso(imo->categoria, tipo_imovel))
    {
        return 1;
    }

    return 0;
}

//Apresenta o numero de identificacao do imovel.
void imovel_apresenta_identificador(Imovel imo)
{
    printf("%d", imo->id);
}

void libera_imovel(Imovel imo)
{
    libera_categoria(imo->categoria, identifica_categoria(imo));
    free(imo->tipo_imovel);
    free(imo->nome_proprietario);
    free(imo);
}

void libera_imovel_nao_utilizado(Imovel imo)
{
    free(imo);
}