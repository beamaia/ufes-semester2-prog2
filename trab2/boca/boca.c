#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOME 40
#define MAX_IMO 300 //quantidade maxima de imoveis permitida no catalogo

/*
Informacoes do arquivo espec.txt como a porcentagem de imoveis caros da lista a,
a porcentagem de terrenos argilosos da lista b e a área e o preço limite das casas
que irão compor a lista c, além da posicao dos identificadores que devem ser somados 
(i, j, k) no final do programa.
*/
typedef struct 
{
    unsigned int percent_caros,
                 percent_argiloso,
                 i,
                 j,
                 k;
    float area_limite,
          preco_limite;
} tEspec;

void inicializa_espec(tEspec *);
void le_espec(tEspec *, FILE *);

// Identificadores referente as posicoes i, j e k estabelecidas pelo arquivo espec.txt
typedef struct 
{
    unsigned int i, j, k;
} tIdentificadores;

void inicializa_identificadores(tIdentificadores *);

void inicializa_espec(tEspec *esp)
{
    esp->percent_caros = 0;
    esp->percent_argiloso = 0;
    esp->i = 0;
    esp->j = 0;
    esp->k = 0;
    esp->area_limite = 0;
    esp->preco_limite = 0;
}

//Leitura dos dados do arquivo espec.txt.
void le_espec(tEspec * esp, FILE * arq)
{
    fscanf(arq, "%d ", &esp->percent_caros);
    fscanf(arq, "%d ", &esp->percent_argiloso);
    fscanf(arq, "%f ", &esp->area_limite);
    fscanf(arq, "%f ", &esp->preco_limite);
    fscanf(arq, "%d %d %d", &esp->i,
                            &esp->j,
                            &esp->k);
}

//Iguala todos identificadores a 0;
void inicializa_identificadores(tIdentificadores *id)
{
    id->i = 0;
    id->j = 0;
    id->k = 0;
}

//Dados do terrento tipo triangulo. Base, altura, tipo de solo e preco do m2
typedef struct 
{
    float base,
          altura;
    char solo;
    unsigned int preco;
} tTriangulo;

void le_triangulo(tTriangulo *,FILE *);
float area_triangulo(tTriangulo *);
float preco_triangulo(tTriangulo *);
int solo_argiloso_triangulo(tTriangulo *);

//Leitura das informacoes do terreno tipo triangulo.
void le_triangulo(tTriangulo *tri, FILE *arq)
{
    fscanf(arq, "%c\n", &tri->solo);
    fscanf(arq, "%d\n", &tri->preco);
    fscanf(arq, "%f\n", &tri->base);
    fscanf(arq, "%f\n", &tri->altura);
}

//Calcula a area do terreno tipo triangulo.
float area_triangulo(tTriangulo *tri)
{
    return (tri->base * tri->altura / 2);
}

//Calcula o preco do terreno tipo triangulo.
float preco_triangulo(tTriangulo *tri)
{
    float fator = 0;
    switch (tri->solo)
    {
        case 'A': return area_triangulo(tri) *  0.9 * ((float) tri->preco);
        case 'G': return area_triangulo(tri) *  1.3 * ((float) tri->preco);
        case 'R': return area_triangulo(tri) * 1.1 * ((float) tri->preco);
        default: return 0;
    }

}

//Verifica se o solo do terreno tipo triangulo e argiloso
int solo_argiloso_triangulo(tTriangulo *tri)
{
    if(tri->solo == 'G')
    {
        return 1;
    }
    
    return 0;
}   

//Dados do terrento tipo trapezio. Base1, base2, altura, tipo de solo e preco do m2
typedef struct 
{
    float base1,
            base2,
            altura;
    char solo;
    int preco;
} tTrapezio;

void le_trapezio(tTrapezio *, FILE *);
float area_trapezio(tTrapezio *);
float preco_trapezio(tTrapezio *);
int solo_argiloso_trapezio(tTrapezio *);

//Leitura das informacoes do terreno tipo trapezio.
void le_trapezio(tTrapezio *tra, FILE *arq)
{
    fscanf(arq, "%c\n", &tra->solo);
    fscanf(arq, "%d\n", &tra->preco);
    fscanf(arq, "%f\n", &tra->base1);
    fscanf(arq, "%f\n", &tra->base2);
    fscanf(arq, "%f\n", &tra->altura);
}

//Calcula a area do terreno tipo trapezio.
float area_trapezio(tTrapezio *tra)
{
    return ((tra->base1 + tra->base2) * tra->altura) / 2;
}

//Calcula o preco do terreno tipo trapezio.
float preco_trapezio(tTrapezio *tra)
{
    switch (tra->solo)
    {
        case 'A': return area_trapezio(tra) * 0.9 * ((float) tra->preco);
        case 'G': return area_trapezio(tra) * 1.3 * ((float) tra->preco);
        case 'R': return area_trapezio(tra) * 1.1 * ((float) tra->preco);
        default: return 0;
    }
}

//Verifica se o solo do terreno tipo trapezio e argiloso.
int solo_argiloso_trapezio(tTrapezio *tra)
{
    if(tra->solo == 'G')
    {
        return 1;
    }
    
    return 0;
}   

//Dados do terrento tipo retangulo. Lado1, lado2, tipo de solo e preco do m2
typedef struct 
{
    float lado1,
            lado2;
    char solo;
    int preco;
} tRetangulo;

void le_retangulo(tRetangulo *, FILE *);
float area_retangulo(tRetangulo *);
float preco_retangulo(tRetangulo *);
int solo_argiloso_retangulo(tRetangulo *);

//Leitura das informacoes do terreno tipo retangulo.
void le_retangulo(tRetangulo *ret, FILE *arq)
{
    fscanf(arq, "%c\n", &ret->solo);
    fscanf(arq, "%d\n", &ret->preco);
    fscanf(arq, "%f\n", &ret->lado1);
    fscanf(arq, "%f\n", &ret->lado2);
}

//Calcula a area do terreno tipo retangulo.
float area_retangulo(tRetangulo *ret)
{
    return ret->lado1 * ret->lado2;
}

//Calcula o preco do terreno tipo retangulo.
float preco_retangulo(tRetangulo *ret)
{
    switch (ret->solo)
    {
        case 'A': return area_retangulo(ret) * 0.9 * ((float) ret->preco);
        case 'G': return area_retangulo(ret) * 1.3 * ((float) ret->preco);
        case 'R': return area_retangulo(ret) * 1.1 * ((float) ret->preco);
        return 0;
    }
}

//Verifica se o solo do terreno tipo retangulo e argiloso.
int solo_argiloso_retangulo(tRetangulo *ret)
{
    if(ret->solo == 'G')
    {
        return 1;
    }
    
    return 0;
}   

/*
Dados da residencia tipo casa. Area do pavimento, area da regiao livre, a quantidade de
pavimentos, o preco do m2 da regiao pavimentada e livre, e a quantidade de quartos e vagas.
*/
typedef struct
{
    float area_pav,
            area_livre;
    int num_pav,
        preco_pav,
        preco_livre,
        num_quartos,
        num_vagas;
} tCasa;

void le_casa(tCasa *, FILE *);
float preco_casa(tCasa *);
float area_cons_casa(tCasa *);
int casa_compara_quartos(tCasa *, tCasa *);

void le_casa(tCasa *casa, FILE *arq)
{
    fscanf(arq, "%d\n", &casa->num_quartos);
    fscanf(arq, "%d\n", &casa->num_vagas);
    fscanf(arq, "%d\n", &casa->num_pav);
    fscanf(arq, "%f\n", &casa->area_pav);
    fscanf(arq, "%d\n", &casa->preco_pav);
    fscanf(arq, "%f\n", &casa->area_livre);
    fscanf(arq, "%d\n", &casa->preco_livre);
}

//Calcula o preco da casa.
float preco_casa(tCasa *casa)
{
    return (casa->preco_pav * casa->num_pav * casa->area_pav) + (casa->preco_livre * casa->area_livre); 
}

//Calcula a area de pavimento da casa a ser considerada para comparacoes futuras.
float area_cons_casa(tCasa *casa)
{
    return casa->area_pav * casa->num_pav;
}

/*
Compara a quantidade de quartos de duas casas. Retorna 1 caso casa1 tem menos quartos que casa2, 
2 caso tenham a mesma quantidade e 0 se for maior
*/
int casa_compara_quartos(tCasa *casa1, tCasa *casa2)
{
    if(casa1->num_quartos < casa2->num_quartos)
    {
        return 1;
    }
    
    if(casa1->num_quartos == casa2->num_quartos)
    {
        return 2;
    }
    
    return 0;
}

typedef struct 
{
    int andar,
        andares_total,
        preco,
        num_quartos,
        num_vagas;
    float area;
    char lazer;
} tApartamento;

void le_apartamento(tApartamento *, FILE *);
float preco_apartamento(tApartamento *);
float area_apartamento(tApartamento *);

//Leitura dos dados referente ao apartamento.
void le_apartamento(tApartamento *apto, FILE *arq)
{
    fscanf(arq, "%d\n", &apto->num_quartos);
    fscanf(arq, "%d\n", &apto->num_vagas);
    fscanf(arq, "%d\n", &apto->andar);
    fscanf(arq, "%f\n", &apto->area);
    fscanf(arq, "%d\n", &apto->preco);
    fscanf(arq, "%c\n", &apto->lazer);
    fscanf(arq, "%d\n", &apto->andares_total);
}

//Calcula o preco do apartamento.
float preco_apartamento(tApartamento *apto)
{
    float lazer = 1;
    if(apto->lazer == 'S')
        lazer = 1.15;
    
    return apto->preco * apto->area * (0.9 + ((float) apto->andar)/apto->andares_total) * lazer;
}

//Retorna a area do apartamento.
float area_apartamento(tApartamento *apto)
{
    return apto->area;
}

/*
Dado referente ao tipo de imovel, podendo ser do tipo triangulo, retangulo, 
trapezio, casa ou apartamento.
*/
typedef union 
{
    tTriangulo tri;
    tRetangulo ret;
    tTrapezio tra;
    tCasa casa;
    tApartamento apto;
} tCategoria;

int le_categoria(tCategoria *, int, FILE *);
float categoria_preco_imovel(tCategoria *, int);
float categoria_area_imovel(tCategoria *, int);
int categoria_compara_quartos(tCategoria *, tCategoria *);
int categoria_identifica_argiloso(tCategoria *, int);

/*
Com base no tipo de imovel que e (triangulo, retangulo, trapezio, casa ou apartamento),
chama a funcao de leitura necessaria.
*/
int le_categoria(tCategoria *cat, int tipo, FILE * arq)
{
    switch (tipo)
    {
        case 1: le_triangulo(&cat->tri, arq);
                return 1;
        case 2: le_retangulo(&cat->ret, arq);
                return 1;
        case 3: le_trapezio(&cat->tra, arq);
                return 1;
        case 4: le_casa(&cat->casa, arq);
                return 1;
        case 5: le_apartamento(&cat->apto, arq);
                return 1;
        default: return 0;
    }
}

/*
Com base no tipo de imovel que e (triangulo, retangulo, trapezio, casa ou apartamento),
chama a funcao de calcular o preco do imovel necessaria.
*/
float categoria_preco_imovel(tCategoria * cat, int tipo)
{
    switch (tipo)
    {
        case 1: return preco_triangulo(&cat->tri);
        case 2: return preco_retangulo(&cat->ret);
        case 3: return preco_trapezio(&cat->tra);
        case 4: return preco_casa(&cat->casa);
        case 5: return preco_apartamento(&cat->apto);
        default: return 0;
    }
}

/*
Com base no tipo de imovel que e (triangulo, retangulo, trapezio, casa ou apartamento),
chama a funcao de calcular a area do imovel necessaria.
*/
float categoria_area_imovel(tCategoria * cat, int tipo)
{
    switch(tipo)
    {
        case 1: return area_triangulo(&cat->tri);
        case 2: return area_retangulo(&cat->ret);
        case 3: return area_trapezio(&cat->tra);
        case 4: return area_cons_casa(&cat->casa);
        case 5: return area_apartamento(&cat->apto);
        default: return 0;
    }
}

/*
Chama a funcao que compara a quantidade de quartos de duas casas. Retorna 1 caso casa da cat1
tem menos quartos que casa da cat2, 2 caso tenham a mesma quantidade e 0 se for maior.
*/
int categoria_compara_quartos(tCategoria *cat1, tCategoria *cat2)
{
    return casa_compara_quartos(&cat1->casa, &cat2->casa);
}

/*
Chama a funcao que retorna o tipo de solo do terreno de acordo com o tipo de terreno.
*/
int categoria_identifica_argiloso(tCategoria *cat, int tipo)
{
    switch(tipo)
    {
        case 1: return solo_argiloso_triangulo(&cat->tri);
        case 2: return solo_argiloso_retangulo(&cat->ret);
        case 3: return solo_argiloso_trapezio(&cat->tra);
        default: return 0;
    }
}

/*
Dados do imovel. O tag do tipo de imovel, o nome do proprietario, o codigo de identificacao,
as informacoes do imovel de acordo com seu tipo, o preco total e a area total construida.
*/
typedef struct 
{
    char tipo_imovel[7],
            nome_proprietario[MAX_NOME];
    int id;
    tCategoria categoria;
    float preco,
            area;
} tImovel;

int identifica_categoria(tImovel *);
int le_imovel(tImovel *, FILE *);
void preco_imovel(tImovel *);
void area_imovel(tImovel *);
int imovel_limite_area_preco(tImovel *, tEspec *);
int compara_id(tImovel *, tImovel *);
int compara_quartos(tImovel *, tImovel *);
int compara_preco(tImovel *, tImovel *);
int compara_area(tImovel *, tImovel *);
void acrescenta_id(tImovel *, int);
int identifica_id(tImovel *);
int imovel_identifica_argiloso(tImovel *);
void imovel_apresenta_identificador(tImovel *);

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

//Dados do catalogo. Um catalogo de varios imoveis e a quantidade de imoveis nesse catalogo.
typedef struct 
{
    tImovel imoveis[MAX_IMO];
    int qtd_imoveis;
} tCatalogo;

void inicializa_catalogo(tCatalogo *);
void le_catalogo(tCatalogo *, FILE *);
void altera_imovel(tCatalogo *, tImovel *);
void inclusao_imovel(tCatalogo *, tImovel *);
void exclusao_imovel(tCatalogo *, tImovel *);
void le_atual(tCatalogo *, FILE *);
void calcula_preco(tCatalogo *);
void calcula_area(tCatalogo *);
void ordena(tCatalogo *, int (* cmp)(tImovel *, tImovel *));
int calcula_qtd_caros(tCatalogo *, tEspec *);
int calcula_qtd_argilosos(tCatalogo *, tEspec *);
void catalogo_argiloso(tCatalogo *, tCatalogo *, tEspec *);
void catalogo_casas(tCatalogo *, tCatalogo *, tEspec *);
void imoveis_mais_caros(tCatalogo *, tEspec *, tIdentificadores *);
void terrenos_argilosos_menores(tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);
void casas_limite(tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);
void apresenta_imoveis_caros(tCatalogo *, int);
void apresenta_terrenos_argilosos(tCatalogo *, int);
void apresenta_casas_limite(tCatalogo *);
void apresenta_catalogos(tCatalogo *, tCatalogo *, tCatalogo *, tIdentificadores *, tEspec *);

//Coloca 0 em quantidade de imoveis do catalogo.
void inicializa_catalogo(tCatalogo *c)
{
    c->qtd_imoveis = 0;
}

/*
Leitura dos imoveis do catalogo, sempre acrescentando 1 a quantidade de imoveis
no catalogo.
*/
void le_catalogo(tCatalogo *c, FILE *arq)
{
    for(int i = 0; i < MAX_IMO && !feof(arq); i++)
    {
        if(le_imovel(&c->imoveis[i], arq))
            c->qtd_imoveis++;
    }
}

//Altera um imovel no catalogo para ser igual ao imovel imo caso seus numeros de identificacao sejam iguais.
void altera_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            c->imoveis[i] = *imo;
            break;
        }
    }
}

/*
Inclui o imovel imo no catalogo caso o catalogo nao tenha mais que o MAX_IMO de imoveis
e aumenta a quantidade de imoveis no catalogo.
*/
void inclusao_imovel(tCatalogo *c, tImovel *imo)
{
    if(c->qtd_imoveis == MAX_IMO)
        return;

    c->imoveis[c->qtd_imoveis] = *imo;
    c->qtd_imoveis++;
}

/*
Procura no catalogo um imovel com o mesmo numero de identificao que o imovel imo, e caso 
tenha, retire-o do catalogo, diminuindo a quantidade de imoveis totais.
*/
void exclusao_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            for(int j = i; j < c->qtd_imoveis - 1 && c->qtd_imoveis < (MAX_IMO + 1); j++)
            {
                c->imoveis[j] = c->imoveis[j + 1];
            }

            c->qtd_imoveis--;
            break;
        }
    }    
}

/*
Leitura do arquivo atual.txt, identifica-se se um imovel deve ser alterado, incluido ou 
excluido e depois chama a funcao necessaria para tal acao.
*/
void le_atual(tCatalogo *c, FILE *arq)
{
    tImovel aux;
    char acao = '0';
    int temp = 0;

    while(!feof(arq) && (c->qtd_imoveis < (MAX_IMO + 1)))
    {
        fscanf(arq, "%c", &acao);
        switch(acao)
        {
            case 'a': le_imovel(&aux, arq);
                      altera_imovel(c, &aux);
                      break;
            case 'i': le_imovel(&aux, arq);
                      inclusao_imovel(c, &aux);
                      break;
            case 'e': fscanf(arq, "%d%*c", &temp);
                      acrescenta_id(&aux, temp);  
                      exclusao_imovel(c, &aux);            
        }
    }
}

//Calcula o preco de todos imoveis do catalogo.
void calcula_preco(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        preco_imovel(&c->imoveis[i]);
    }
}

//Calcula a area de todos imoveis do catalogo.
void calcula_area(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        area_imovel(&c->imoveis[i]);
    }
}

//Ordena o catalogo com base em uma funcao que recebe (tImovel *, tImovel *) como parametro.
void ordena(tCatalogo *c, int (* cmp)(tImovel *, tImovel *))
{
    tImovel aux;
    for(int i = 0; i < c->qtd_imoveis - 1 && c->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        for(int j = 0; j < c->qtd_imoveis - i - 1; j++)
        {
            if((*cmp)(&c->imoveis[j], &c->imoveis[j + 1]))
            {
                aux = c->imoveis[j];
                c->imoveis[j] = c->imoveis[j + 1];
                c->imoveis[j + 1] = aux;
            }
        }
    }
}

//Calcula a quantidade de imoveis que serao apresentados.
int calcula_qtd_caros(tCatalogo *c1, tEspec *espec)
{
    return espec->percent_caros * c1->qtd_imoveis / 100;
}

//Calcula a quantidade de imoveis argilosos que serao apresentados.
int calcula_qtd_argilosos(tCatalogo *c, tEspec *espec)
{
    return espec->percent_argiloso * c->qtd_imoveis / 100;
}


//Cria um catalogo c2 baseado nos terrenos argilosos do catalogo c1.
void catalogo_argiloso(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    for(int i = 0; i < c1->qtd_imoveis && c1->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(imovel_identifica_argiloso(&c1->imoveis[i]))
        {
            c2->imoveis[c2->qtd_imoveis] = c1->imoveis[i];
            c2->qtd_imoveis++;
        }
    }
}

//Cria um catalogo c2 baseado nas casas dentro do limite das informacoes do arquivo espec.txt.
void catalogo_casas(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    for(int i = 0; i < c1->qtd_imoveis && c1->qtd_imoveis < (MAX_IMO + 1); i++)
    {
        if(identifica_categoria(&c1->imoveis[i]) == 4)
        {
            if(imovel_limite_area_preco(&c1->imoveis[i], espec))
            {
                c2->imoveis[c2->qtd_imoveis] = c1->imoveis[i];
                c2->qtd_imoveis++;
            }
        }       
    }
}

/*
Executa o item a. Chama a funcao ordena, utilizando para comparacao o preco. E por ultimo,
armazena o numero de identificao do catalogo de acordo com as informacoes do arquivo 
espec.txt.
*/ 
void imoveis_mais_caros(tCatalogo *c, tEspec *espec, tIdentificadores *id)
{
    if(!c->qtd_imoveis)
    {
        return;
    }

    ordena(c, compara_preco);

    int limite = calcula_qtd_caros(c, espec);

    if(espec->i > c->qtd_imoveis || espec->i == 0)
    {
        id->i = 0;
    }
    else
    {
        id->i = identifica_id(&c->imoveis[espec->i - 1 + c->qtd_imoveis - limite]);
    }
}

/*
Executa o item b. Cria um catalogo de imoveis argilosos, chama a funcao ordena, utilizando 
para comparacao a area. E por ultimo, armazena o numero de identificao do catalogo de imoveis
argilosos de acordo com as informacoes do arquivo espec.txt.
*/
void terrenos_argilosos_menores(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_argiloso(c1, c2, espec);

    if(!c2->qtd_imoveis)
    {
        return;
    }

    ordena(c2, compara_area);
    int limite = calcula_qtd_argilosos(c2, espec);

    if(espec->j > c2->qtd_imoveis || espec->j == 0)
    {
        id->j = 0;
    }
    else
    {
        id->j = identifica_id(&c2->imoveis[espec->j - 1 + c2->qtd_imoveis - limite]);
    }

}

/*
Executa o item c. Cria um catalogo de imoveis de casas, chama a funcao ordena, utilizando 
para comparacao a quantidade de quartos. E por ultimo, armazena o numero de identificao do 
catalogo de imoveis de casas de acordo com as informacoes do arquivo espec.txt.
*/
void casas_limite(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_casas(c1, c2, espec);

    if(!c2->qtd_imoveis)
    {
        return;
    }

    ordena(c2, compara_quartos);
    
    if(espec->k > c2->qtd_imoveis || espec->k == 0)
    {
        id->k = 0;
    }
    else
    {
        id->k = identifica_id(&c2->imoveis[espec->k - 1]);
    }
}

//Apresenta o numero de identificao dos imoveis mais caros.
void apresenta_imoveis_caros(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis && i >= 0 && i < MAX_IMO; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }
    if(c->qtd_imoveis)
        printf("\n");

}

//Apresenta o numero de identificacao dos terrenos argilosos.
void apresenta_terrenos_argilosos(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis && i < MAX_IMO; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
        }
    if(c->qtd_imoveis)
        printf("\n");
}

//Apresenta o numero de identificacao das casas.
void apresenta_casas_limite(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis && i < MAX_IMO; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }
    if(c->qtd_imoveis)
     printf("\n");
}

/*
Cria um arquivo saida.txt com a soma dos identificadores especificados pelo arquivo espec.txt e os numeros de 
identificacao dos imoveis mais caros, terrenos argilosos e das casas, de acordo com as informacoes do arquivo 
espec.txt
*/
void apresenta_catalogos(tCatalogo *c1, tCatalogo *c2, tCatalogo *c3, tIdentificadores *id, tEspec *espec)
{
    printf("%d\n", id->i + id->j + id->k);
    if(c1->qtd_imoveis)
    {
        apresenta_imoveis_caros(c1, calcula_qtd_caros(c1, espec));
        apresenta_terrenos_argilosos(c2, calcula_qtd_argilosos(c2, espec));
        apresenta_casas_limite(c3);
    }
}

int main()
{
    char arq_path1[150], arq_path2[150], arq_path3[150];
    scanf("%s", arq_path1);
    FILE *arq_cat = fopen(arq_path1, "r");
    scanf("%s", arq_path2);
    FILE *arq_atual = fopen(arq_path2, "r");
    scanf("%s", arq_path3);
    FILE *arq_espec = fopen(arq_path3, "r");

    if(arq_cat == NULL || arq_atual == NULL || arq_espec == NULL)
    {
        printf("Arquivo não encontrado\n");
        exit(1);
    }

    tCatalogo imoveis, casas, argilosos;
    tEspec espec;
    tIdentificadores id;

    inicializa_catalogo(&imoveis);
    inicializa_catalogo(&casas);
    inicializa_catalogo(&argilosos);
    le_catalogo(&imoveis, arq_cat);
    le_atual(&imoveis, arq_atual);

    if(imoveis.qtd_imoveis)
    {
        inicializa_espec(&espec);
        le_espec(&espec, arq_espec);
        calcula_area(&imoveis);
        calcula_preco(&imoveis);
        imoveis_mais_caros(&imoveis, &espec, &id);
        terrenos_argilosos_menores(&imoveis, &argilosos, &id, &espec);
        casas_limite(&imoveis, &casas, &id, &espec);
    }
    apresenta_catalogos(&imoveis, &argilosos, &casas, &id, &espec);

    fclose(arq_atual);
    fclose(arq_cat);
    fclose(arq_espec);
    return 0;
}