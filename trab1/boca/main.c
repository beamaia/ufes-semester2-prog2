#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NOME 40
#define MAX_IMO 300

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

void le_espec(tEspec * esp, FILE * arq)
{
    fscanf(arq, "%d%*c", &esp->percent_caros);
    fscanf(arq, "%d%*c", &esp->percent_argiloso);
    fscanf(arq, "%f%*c", &esp->area_limite);
    fscanf(arq, "%f%*c", &esp->preco_limite);
    fscanf(arq, "%d%*c%d%*c%d%*c", &esp->i,
                                  &esp->j,
                                  &esp->k);
}

typedef struct 
{
    unsigned int i,
                    j,
                    k;
} tIdentificadores;

typedef struct 
{
    float base,
            altura,
            area;
    char solo;
    unsigned int preco;
} tTriangulo;

//Leitura das informacoes do terreno tipo triangulo
void le_triangulo(tTriangulo *tri, FILE *arq)
{
    fscanf(arq, "%c%*c", &tri->solo);
    fscanf(arq, "%d%*c", &tri->preco);
    fscanf(arq, "%f%*c", &tri->base);
    fscanf(arq, "%f%*c", &tri->altura);
}

//Calcula a area do terreno tipo triangulo
float area_triangulo(tTriangulo *tri)
{
    return (tri->base * tri->altura / 2.0);
}

//Calcula o preco do terreno tipo triangulo
float preco_triangulo(tTriangulo *tri)
{
    float fator;
    switch (tri->solo)
    {
        case 'A': fator =  0.9 * ((float) tri->preco);
                  break;
        case 'G': fator =  1.3 * ((float) tri->preco);
                  break;
        case 'R': fator = 1.1 * ((float) tri->preco);
    }

    return area_triangulo(tri) * fator;
}

//Verifica se o solo do terreno tipo triangulo e argiloso
int solo_argiloso_triangulo(tTriangulo *tri)
{
    if(tri->solo == 'G')
        return 1;
    
    return 0;
}   

typedef struct 
{
    float base1,
            base2,
            altura;
    char solo;
    unsigned int preco;
} tTrapezio;

//Leitura das informacoes do terreno tipo trapezio
void le_trapezio(tTrapezio *tra, FILE *arq)
{
    fscanf(arq, "%c%*c", &tra->solo);
    fscanf(arq, "%d%*c", &tra->preco);
    fscanf(arq, "%f%*c", &tra->base1);
    fscanf(arq, "%f%*c", &tra->base2);
    fscanf(arq, "%f%*c", &tra->altura);
}

//Calcula a area do terreno tipo trapezio
float area_trapezio(tTrapezio *tra)
{
    float x = ((tra->base1 + tra->base2) * tra->altura) / ((float) 2.0);
    return x;
}

//Calcula o preco do terreno tipo trapezio
float preco_trapezio(tTrapezio *tra)
{
    float fator = 0;
    switch (tra->solo)
    {
        case 'A': fator = 0.9 * ((float) tra->preco);
                  break;
        case 'G': fator = 1.3 * ((float) tra->preco);
                  break;
        case 'R': fator = 1.1 * ((float) tra->preco);
    }

    return area_trapezio(tra) * fator;
}

//Verifica se o solo do terreno tipo trapezio e argiloso
int solo_argiloso_trapezio(tTrapezio *tra)
{
    if(tra->solo == 'G')
        return 1;
    
    return 0;
}   

    typedef struct 
    {
        float lado1,
              lado2;
        char solo;
        unsigned int preco;
    } tRetangulo;

//Leitura das informacoes do terreno tipo retangulo
void le_retangulo(tRetangulo *ret, FILE *arq)
{
    fscanf(arq, "%c%*c", &ret->solo);
    fscanf(arq, "%d%*c", &ret->preco);
    fscanf(arq, "%f%*c", &ret->lado1);
    fscanf(arq, "%f%*c", &ret->lado2);
}

//Calcula a area do terreno tipo retangulo
float area_retangulo(tRetangulo *ret)
{
    return ret->lado1 * ret->lado2;
}

//Calcula o preco do terreno tipo retangulo
float preco_retangulo(tRetangulo *ret)
{
    float fator;
    switch (ret->solo)
    {
        case 'A': fator = 0.9 * ((float) ret->preco);
                  break;
        case 'G': fator = 1.3 * ((float) ret->preco);
                  break;
        case 'R': fator = 1.1 * ((float) ret->preco);
    }
    return area_retangulo(ret) * fator;
}

//Verifica se o solo do terreno tipo retangulo e argiloso
int solo_argiloso_retangulo(tRetangulo *ret)
{
    if(ret->solo == 'G')
        return 1;
    
    return 0;
}   

typedef struct
{
    float area_pav,
            area_livre;
    unsigned int num_pav,
                    preco_pav,
                    preco_livre,
                    num_quartos,
                    num_vagas;
} tCasa;

//Leitura dos dados referente a casa
void le_casa(tCasa *casa, FILE *arq)
{
    fscanf(arq, "%d%*c", &casa->num_quartos);
    fscanf(arq, "%d%*c", &casa->num_vagas);
    fscanf(arq, "%d%*c", &casa->num_pav);
    fscanf(arq, "%f%*c", &casa->area_pav);
    fscanf(arq, "%d%*c", &casa->preco_pav);
    fscanf(arq, "%f%*c", &casa->area_livre);
    fscanf(arq, "%d%*c", &casa->preco_livre);
}

//Calcula o preco da casa
float preco_casa(tCasa *casa)
{
    return (casa->preco_pav * casa->num_pav * casa->area_pav) + (casa->preco_livre * casa->area_livre); 
}

//Calcula a area da casa a ser considerada para comparacoes futuras
float area_cons_casa(tCasa *casa)
{
    return casa->area_pav * casa->num_pav;
}

//Compara a quantidade de quartos de duas casas. Retorna 1 caso casa1 tem meenos quartos que casa2, 2 caso tenham a mesma quantidade e 0 se for maior
int casa_compara_quartos(tCasa *casa1, tCasa *casa2)
{
    if(casa1->num_quartos < casa2->num_quartos)
        return 1;
    
    if(casa1->num_quartos == casa2->num_quartos)
        return 2;
    
    return 0;
}

typedef struct 
{
    unsigned int andar,
                    preco,
                    andares_total,
                    num_quartos,
                    num_vagas;
    float area;
    char lazer;
} tApartamento;

//Leitura dos dados referente ao apartamento
void le_apartamento(tApartamento *apto, FILE *arq)
{
    fscanf(arq, "%d%*c", &apto->num_quartos);
    fscanf(arq, "%d%*c", &apto->num_vagas);
    fscanf(arq, "%d%*c", &apto->andar);
    fscanf(arq, "%f%*c", &apto->area);
    fscanf(arq, "%d%*c", &apto->preco);
    fscanf(arq, "%c%*c", &apto->lazer);
    fscanf(arq, "%d%*c", &apto->andares_total);
}

//Calcula o preco do apartamento
float preco_apartamento(tApartamento *apto)
{
    float lazer = 1;
    if(apto->lazer == 'S')
        lazer = 1.15;
    
    return apto->preco * apto->area * (0.9 + ((float) apto->andar)/apto->andares_total) * lazer;
}

float area_apartamento(tApartamento *apto)
{
    return apto->area;
}

typedef union 
{
    tTriangulo tri;
    tRetangulo ret;
    tTrapezio tra;
    tCasa casa;
    tApartamento apto;
} tCategoria;

void le_categoria(tCategoria *cat, int tipo, FILE * arq)
{
    switch (tipo)
    {
        case 1: le_triangulo(&cat->tri, arq);
                return;
        case 2: le_retangulo(&cat->ret, arq);
                return;
        case 3: le_trapezio(&cat->tra, arq);
                return;
        case 4: le_casa(&cat->casa, arq);
                return;
        case 5: le_apartamento(&cat->apto, arq);
    }
}

float preco_imovel_categoria(tCategoria * cat, int tipo)
{
    switch (tipo)
    {
        case 1: return preco_triangulo(&cat->tri);
        case 2: return preco_retangulo(&cat->ret);
        case 3: return preco_trapezio(&cat->tra);
        case 4: return preco_casa(&cat->casa);
        case 5: return preco_apartamento(&cat->apto);
    }
}

float area_imovel_categoria(tCategoria * cat, int tipo)
{
    switch(tipo)
    {
        case 1: return area_triangulo(&cat->tri);
        case 2: return area_retangulo(&cat->ret);
        case 3: return area_trapezio(&cat->tra);
        case 4: return area_cons_casa(&cat->casa);
        case 5: return area_apartamento(&cat->apto);
    }

    return 0;
}

int categoria_compara_quartos(tCategoria *cat1, tCategoria *cat2)
{
    return casa_compara_quartos(&cat1->casa, &cat2->casa);
}

int categoria_identifica_argiloso(tCategoria *cat, int tipo)
{
    switch(tipo)
    {
        case 1: return solo_argiloso_triangulo(&cat->tri);
        case 2: return solo_argiloso_retangulo(&cat->ret);
        case 3: return solo_argiloso_trapezio(&cat->tra);
    }

    return 0;
}

typedef struct 
{
    char tipo_imovel[7],
            nome_proprietario[MAX_NOME];
    unsigned int id;
    tCategoria categoria;
    float preco,
            area;
} tImovel;

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
}

void le_imovel(tImovel *imo, FILE *arq)
{
    fscanf(arq, "%s%*c", imo->tipo_imovel);
    fscanf(arq, "%d%*c", &imo->id);
    fscanf(arq, "%[^\n]%*c ", imo->nome_proprietario);
    
    int cat = identifica_categoria(imo);
    le_categoria(&imo->categoria, cat, arq);
}

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

void preco_imovel(tImovel *imo)
{
    imo->preco = preco_imovel_categoria(&imo->categoria, identifica_categoria(imo));
}

void area_imovel(tImovel *imo)
{
    imo->area = area_imovel_categoria(&imo->categoria, identifica_categoria(imo));
}

int imovel_limite_area_preco(tImovel *imo, tEspec *espec)
{
    if(imo->area > espec->area_limite && imo->preco < espec->preco_limite)
        return 1;
    
    return 0;
}

int compara_id(tImovel *imo1, tImovel *imo2)
{
    return imo1->id == imo2->id;
}

void acrescenta_id(tImovel *imo, int id)
{
    imo->id = id;
}

int compara_quartos(tImovel *imo1, tImovel *imo2)
{
    int situacao = categoria_compara_quartos(&imo1->categoria, &imo2->categoria);
    if(situacao == 1 || (situacao == 2 && imo1->id < imo2->id))
        return 1;

    return 0;
}

int compara_preco(tImovel *imo1, tImovel *imo2)
{
    if(imo1->preco > imo2->preco || (imo1->preco == imo2->preco && imo1->id > imo2->id))
        return 1;

    return 0;
}

int compara_area(tImovel *imo1, tImovel *imo2)
{
    if(imo1->area < imo2->area || (imo1->area == imo2->area && imo1->id > imo2->id))
        return 1;
        
    return 0;
}

int identifica_id(tImovel *imo)
{
    return imo->id;
}

int imovel_identifica_argiloso(tImovel *imo)
{
    int tipo_imovel = identifica_categoria(imo);
    if(categoria_identifica_argiloso(&imo->categoria, tipo_imovel))
        return 1;
    
    return 0;
}

void imovel_apresenta_identificador(tImovel *imo)
{
    printf("%d", imo->id);
}


typedef struct 
{
    tImovel imoveis[MAX_IMO];
    unsigned int qtd_imoveis;
} tCatalogo;

void inicializa_catalogo(tCatalogo *c)
{
    c->qtd_imoveis = 0;
}

void le_catalogo(tCatalogo *c, FILE *arq)
{
    while(!feof(arq) && c->qtd_imoveis < 301)
    {
        c->qtd_imoveis++;
        le_imovel(&c->imoveis[c->qtd_imoveis - 1], arq);
        fscanf(arq, "\n");

    }
}

void altera_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            modifica_imovel(&c->imoveis[i], imo);
            break;
        }
    }
}

void inclusao_imovel(tCatalogo *c, tImovel *imo)
{
    if(c->qtd_imoveis == 300)
        return;

    c->imoveis[c->qtd_imoveis] = *imo;
    c->qtd_imoveis++;
}

void exclusao_imovel(tCatalogo *c, tImovel *imo)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        if(compara_id(&c->imoveis[i], imo))
        {
            c->qtd_imoveis--;
            for(int j = i; j < c->qtd_imoveis; j++)
            {
                modifica_imovel(&c->imoveis[j], &c->imoveis[j + 1]);
            }
            break;
        }
    }    
}

void le_atual(tCatalogo *c, FILE *arq)
{
    tImovel aux;
    char acao;
    int temp;

    while(!feof(arq) && (c->qtd_imoveis < 301))
    {
        fscanf(arq, "%c%*c", &acao);
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
        fscanf(arq, "%*c");
    }
}

void calcula_preco(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        preco_imovel(&c->imoveis[i]);
    }
}

void calcula_area(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        area_imovel(&c->imoveis[i]);
    }
}

void ordena(tCatalogo *c, int (* cmp)(tImovel *, tImovel *))
{
    tImovel aux;
    for(int i = 0; i < c->qtd_imoveis - 1; i++)
    {
        for(int j = 0; j < c->qtd_imoveis - i - 1; j++)
        {
            if((*cmp)(&c->imoveis[j], &c->imoveis[j + 1]))
            {
                modifica_imovel(&aux, &c->imoveis[j]);
                modifica_imovel(&c->imoveis[j], &c->imoveis[j + 1]);
                modifica_imovel(&c->imoveis[j + 1], &aux);
            }
        }
    }
}

int calcula_qtd_caros(tCatalogo *c1, tEspec *espec)
{
    return espec->percent_caros * c1->qtd_imoveis / 100;
}

void imoveis_mais_caros(tCatalogo *c, tEspec *espec, tIdentificadores *id)
{
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

int calcula_qtd_argilosos(tCatalogo *c, tEspec *espec)
{
    return espec->percent_argiloso * c->qtd_imoveis / 100;
}

void catalogo_argiloso(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    inicializa_catalogo(c2);
    for(int i = 0; i < c1->qtd_imoveis; i++)
    {
        if(imovel_identifica_argiloso(&c1->imoveis[i]))
        {
            modifica_imovel(&c2->imoveis[c2->qtd_imoveis], &c1->imoveis[i]);
            c2->qtd_imoveis++;
        }
    }
}

void terrenos_argilosos_menores(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_argiloso(c1, c2, espec);
    ordena(c2, compara_area);

    if(espec->j > c2->qtd_imoveis || espec->j == 0)
    {
        id->j = 0;
    }
    else
    {
        id->j = identifica_id(&c2->imoveis[espec->j - 1]);
    }

}

void catalogo_casas(tCatalogo *c1, tCatalogo *c2, tEspec *espec)
{
    inicializa_catalogo(c2);
    for(int i = 0; i < c1->qtd_imoveis; i++)
    {
        if(identifica_categoria(&c1->imoveis[i]) == 4)
        {
            if(imovel_limite_area_preco(&c1->imoveis[i], espec))
            {
                modifica_imovel(&c2->imoveis[c2->qtd_imoveis], &c1->imoveis[i]);
                c2->qtd_imoveis++;
            }
        }       
    }
}

void casas_limite(tCatalogo *c1, tCatalogo *c2, tIdentificadores *id, tEspec *espec)
{
    catalogo_casas(c1, c2, espec);
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

void apresenta_imoveis_caros(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    printf("\n");

}

void apresenta_terrenos_argilosos(tCatalogo *c, int limite)
{
    for(int i = c->qtd_imoveis - limite; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

void apresenta_casas_limite(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_imoveis; i++)
    {
        imovel_apresenta_identificador(&c->imoveis[i]);
        if(i != c->qtd_imoveis - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

void apresenta_catalogos(tCatalogo *c1, tCatalogo *c2, tCatalogo *c3, tIdentificadores *id, tEspec *espec)
{
    printf("%d\n", id->i + id->j + id->k);
    apresenta_imoveis_caros(c1, calcula_qtd_caros(c1, espec));
    apresenta_terrenos_argilosos(c2, calcula_qtd_argilosos(c2, espec));
    apresenta_casas_limite(c3);
}

int main()
{
    char arq_path[150];
    scanf("%s", arq_path);
    FILE *arq_cat = fopen(arq_path, "r");
    scanf("%s", arq_path);
    FILE *arq_atual = fopen(arq_path, "r");
    scanf("%s", arq_path);
    FILE *arq_espec = fopen(arq_path, "r");

    if(!arq_cat || !arq_atual || !arq_espec)
    {
        printf("Arquivo não encontrado\n");
        exit(1);
    }

    tCatalogo imoveis, casas, argilosos;
    tEspec espec;
    tIdentificadores id;

    inicializa_catalogo(&imoveis);
    le_catalogo(&imoveis, arq_cat);
    le_atual(&imoveis, arq_atual);
    le_espec(&espec, arq_espec);
    calcula_area(&imoveis);
    calcula_preco(&imoveis);
    imoveis_mais_caros(&imoveis, &espec, &id);
    terrenos_argilosos_menores(&imoveis, &argilosos, &id, &espec);
    casas_limite(&imoveis, &casas, &id, &espec);
    apresenta_catalogos(&imoveis, &argilosos, &casas, &id, &espec);

    fclose(arq_atual);
    fclose(arq_cat);
    fclose(arq_espec);
    return 0;
}