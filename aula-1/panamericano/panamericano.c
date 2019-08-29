/* 
Pais / Medalhas de ouro / Medalhas de prata / Medalha de bronze
termina com pais string nula

1) Apresenta tabela em ordem alfabetica de pais
2) Apresenta tabela em ordem de classificacao (mais ouro, dps quem tem mais prata e por ultimo mais bronze)
3) Apresenta tabela com paise que tem pelo menos 1 medalha ordenado por total de medalhas
4) Apresenta tabela so com paises que tem pelo menos 1 medalha ordenado por onde 1 ouro = 2 prata e 1 prata = 2 bronze; 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PAIS 50
#define MAX_NOME 50

//Informacao sobre datas
typedef struct{
    int ouro;
    int prata;
    int bronze;
    int total;
} tMedalhas;

tMedalhas le_medalhas()
{
    tMedalhas medalhas;

    printf("QUANTIDADE DE MEDALHAS DE OURO:\n");
    scanf("%d", &medalhas.ouro);
    printf("QUANTIDADE DE MEDALHAS DE PRATA:\n");
    scanf("%d", &medalhas.prata);
    printf("QUANTIDADE DE MEDALHAS DE BRONZE:\n");
    scanf("%d", &medalhas.bronze);

    return medalhas;
}
int compara_medalhas(tMedalhas pais1, tMedalhas pais2)
{
    if(pais1.ouro > pais2.ouro)
        return 1;
    else if(pais1.ouro == pais2.ouro)
        if(pais1.prata > pais2.prata)
            return 1;
        else if(pais1.prata == pais2.prata)
            if(pais1.bronze > pais2.bronze )
                return 1;
    
    return 0;
}

int calcula_total(tMedalhas medalhas)
{
    return medalhas.ouro + medalhas.prata + medalhas.bronze;
}

int tem_medalha(tMedalhas medalhas)
{
    if(medalhas.total > 0)
        return 1;
    return 0;
}

void apresenta_medalhas(tMedalhas medalhas)
{
    printf("|     OURO     |\n");
    printf("|%-14|\n", medalhas.ouro);
    printf("|     PRATA    |\n");
    printf("|%-14|\n", medalhas.prata);
    printf("|    BRONZE    |\n");
    printf("|%-14|\n", medalhas.bronze);
}

typedef struct{
    char nome[MAX_NOME];
    tMedalhas medalhas;
    int pontuacao;
    int classificacao;
} tPais;

tPais le_nome_do_pais()
{
    tPais pais; 
    printf("PAIS:\n");
    scanf("%s", pais.nome);  
    return pais;  
}

tPais le_medalhas_do_pais()
{
    tPais pais;
    pais.medalhas = le_medalhas();
    return pais;
}

tPais le_pais()
{
    tPais pais;
    pais = le_nome_do_pais();
    pais = le_medalhas_do_pais();
    return pais;
}

int compara_nomes(tPais pais1, tPais pais2)
{
    if(strcmp(pais1.nome, pais2.nome) < 0) 
        return 1;
    else    
        return 0;
}

void apresenta_pais(tPais pais)
{
    printf("|     PAÍS     |\n");
    printf("|%-14s|\n", pais.nome);
    apresenta_medalhas(pais.medalhas);
}

typedef struct{
    tPais pais[MAX_PAIS];
    int qtd_paises;
} tPanamericano;

tPanamericano le_todos_os_paises()
{
    tPanamericano jogos;

    for (int i = 0; i < MAX_NOME; i++)
    {
        jogos.pais[i] = le_pais();

        if()
    }
    
    jogos.qtd_paises = i;
    return jogos;
}

tPanamericano troca(tPanamericano jogo, int j)
{
    tPais temp;

    temp = jogo.pais[j];
    jogo.pais[j] = jogo.pais[j + 1];
    jogo.pais[j + 1] = temp;

    return jogo;
}

ordena_por_nome_do_pais(tPanamericano jogo)
{
    for(int i = 0; i < jogo.qtd_paises - 1; i++)
    {
        for(int j = 0; j < jogo.qtd_paises - 1; j++)
        {
            if(compara_nomes(jogo.pais[j], jogo.pais[j+1])) 
            {
                jogo = troca(jogo);
            }
        }
    }
}

int main()
{
    tPanamericano jogos;
    jogos = le_todos_os_paises();

}