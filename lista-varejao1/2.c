#include <stdio.h>

typedef struct{
    int ouro;
    int prata;
    int bronze;
} tMedalhas;

int comp_qtd(int a, int b)
{
    if(a > b)
        return 0;
    else if(a == b)
        return 2;
    else
        return 1;
}

void adiciona_medalha(int i, tMedalhas * m)
{
    if(i == 0)
    {
        m->ouro++;
    }
    else if(i == 1)
    {
        m->prata++;
    }
    else if (i == 2)
    {
        m->bronze++;
    }
}

void zera_medalhas(tMedalhas *m)
{
    m->ouro = 0;
    m->prata = 0;
    m->bronze = 0;
}

int comp_medalhas(tMedalhas a, tMedalhas b, int med)
{
    if(med == 0)
    {
        return comp_qtd(a.ouro, b.ouro);
    }
    else if(med == 1)
    {
        return comp_qtd(a.prata, b.prata);
    }
    else
    {
        return comp_qtd(a.bronze, b.bronze);
    }   
}

void apresenta_medalhas(tMedalhas m, FILE * fp)
{
    fprintf(fp, "%d %d %d\n", m.ouro, m.prata, m.bronze);
}

typedef struct{
    int cod;
    tMedalhas medalhas;
} tPais;

int comp_pais(tPais a, tPais b, int med)
{
    return comp_medalhas(a.medalhas, b.medalhas, med);
}

void leia_cod(int *a, FILE *fp)
{
    fscanf(fp, "%d", a);
}

int cod_iguais(int a, tPais p)
{
    return a == p.cod;
}

void adiciona_cod(int cod, tPais * p)
{
    p->cod = cod;
}

void zera_pais(tPais * p)
{
    zera_medalhas(&p->medalhas);
}

void modifica_medalhas_pais(int i, tPais *p)
{
    adiciona_medalha(i, &p->medalhas);
}

void apresenta_pais(tPais p, FILE * fp)
{
    fprintf(fp, "%d ", p.cod);
    apresenta_medalhas(p.medalhas, fp);
}

typedef struct{
    tPais pais[30];
    int qtd_paises;
} tComp;


int checa_cod(int a, tComp * p)
{
    for(int i = 0; i < p->qtd_paises; i++)
    {
        if(cod_iguais(a, p->pais[i]))
        {
            return i;
        }
    }

    return -1;
}

void leia_comp(tComp * jogo, FILE * fp)
{
    jogo->qtd_paises = 0;
    int cod, tem_cod;
    while(feof(fp) == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            leia_cod(&cod, fp);
            tem_cod = checa_cod(cod, jogo);
            if(tem_cod == -1)
            {
                jogo->qtd_paises++;
                zera_pais(&jogo->pais[jogo->qtd_paises - 1]);
                adiciona_cod(cod, &jogo->pais[jogo->qtd_paises - 1]);
                modifica_medalhas_pais(i, &jogo->pais[jogo->qtd_paises - 1]);
            }
            else
            {
                modifica_medalhas_pais(i, &jogo->pais[tem_cod]);
            }
        }   
    }
}

void ordena(tComp * jogo)
{
    int med, sit;
    tPais aux;
    for(int i = 0;  i< jogo->qtd_paises - 1; i++)
    {
        med = 0;
        for(int j = 0; j < jogo->qtd_paises - i - 1; j++)
        {
            while(med < 3)
            {
                sit = comp_pais(jogo->pais[j], jogo->pais[j + 1], med);
                if(sit == 1)
                {
                    aux = jogo->pais[j];
                    jogo->pais[j] = jogo->pais[j + 1];
                    jogo->pais[j + 1] = aux;
                    break;
                }
                else if(sit == 2)
                {
                    med++;
                    continue;
                }
                else
                {
                    break;
                }
                
            }

            med = 0;
        }
    }
}

void apresenta_jogo(tComp jogo, FILE * fp)
{
    for(int i = 0; i < jogo.qtd_paises; i++)
    {
        apresenta_pais(jogo.pais[i], fp);
    }
}

int main()
{
    tComp jogo;
    FILE * fp = fopen("entrada_2.txt", "r");
    FILE * fw = fopen("saida_2.txt", "w");

    if(fp == NULL)
    {
        printf("Nao ha arq\n");
    }
    else
    {
        leia_comp(&jogo, fp);
        ordena(&jogo);
        apresenta_jogo(jogo, fw);
        fclose(fp);
    }

    fclose(fw);
    return 0;
}