#include <stdio.h>
#include <string.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "imovel.h"
#include "espec.h"

/*
Identifica qual e a categoria escolhida:
1: Triangulo
2: Retangulo
3: Trapezio
4: Casa
5: Apartamento
*/
int identifica_categoria(tImovel *imo)
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

//Leitura dos dados do imovel. Retorna 1 caso foi feito a leitura de um imovel, 0 caso o contrario.
int le_imovel(tImovel *imo, FILE *arq)
{
    fscanf(arq, "%s\n", imo->tipo_imovel);
    fscanf(arq, "%d\n", &imo->id);
    fscanf(arq, "%[^\n]\n ", imo->nome_proprietario);
    
    int cat = identifica_categoria(imo);
    return le_categoria(&imo->categoria, cat, arq);
}

//Iguala as informacoes do imovel imo1 ao do imovel imo2.
void modifica_imovel(tImovel *imo1, tImovel *imo2)
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

//Chama a funcao que retorna o preco total to imovel e armezena o valor dentro do struct tImovel.
void preco_imovel(tImovel *imo)
{
    imo->preco = categoria_preco_imovel(&imo->categoria, identifica_categoria(imo));
}

//Chama a funcao que retorna a area total construida to imovel e armezena o valor dentro do struct tImovel.
void area_imovel(tImovel *imo)
{
    imo->area = categoria_area_imovel(&imo->categoria, identifica_categoria(imo));
}

//Verifica se a cara esta dentro do limite de area e preco de acordo com as informacoes do arquivo espec.txt.
int imovel_limite_area_preco(tImovel *imo, tEspec *espec)
{
    if(imo->area > espec->area_limite && imo->preco < espec->preco_limite)
    {
        return 1;
    }

    return 0;
}

//Verifica se o numero de identificao de imoveis diferentes sao iguais.
int compara_id(tImovel *imo1, tImovel *imo2)
{
    return imo1->id == imo2->id;
}

//Associa um numero de identificao id a um imovel imo.
void acrescenta_id(tImovel *imo, int id)
{
    imo->id = id;
}

/*
Compara a quantidade de quartos de dois imoveis, retorna 1 caso o imovel imo1
tenha menos quartos ou se tem a mesma quantidade, porem o identificador do 
imovel imo1 seja menor que o do imovel imo2. Retorna 0 caso o imovel imo2 tenha
menos quartos.
*/
int compara_quartos(tImovel *imo1, tImovel *imo2)
{
    int situacao = categoria_compara_quartos(&imo1->categoria, &imo2->categoria);
    if(situacao == 1 || (situacao == 2 && imo1->id < imo2->id))
        return 1;

    return 0;
}

/*
Compara o preco de dois imoveis e retorna 1 caso o imovel imo1 seja mais caro ou
se os imoveis apresentam o mesmo preco, porem o identificador do imovel imo1 seja
maior que o imovel imo2. Retorna 0 caso o imovel imo2 seja mais caro.
*/
int compara_preco(tImovel *imo1, tImovel *imo2)
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
int compara_area(tImovel *imo1, tImovel *imo2)
{
    if(imo1->area < imo2->area || (imo1->area == imo2->area && imo1->id > imo2->id))
        return 1;
        
    return 0;
}

//Retorna o numero de identificao do imovel.
int identifica_id(tImovel *imo)
{
    return imo->id;
}

//Chama a funcao que verifica se o imovel tem um solo argiloso.
int imovel_identifica_argiloso(tImovel *imo)
{
    int tipo_imovel = identifica_categoria(imo);
    if(categoria_identifica_argiloso(&imo->categoria, tipo_imovel))
    {
        return 1;
    }

    return 0;
}

//Apresenta o numero de identificacao do imovel.
void imovel_apresenta_identificador(tImovel *imo)
{
    printf("%d", imo->id);
}
