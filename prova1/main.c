/*
 Entrada: Nome do time, gols, Nome do time, gols
 Empate : 1 ponto, Ganhar: 2 pontos
 Saida: Ponto, Vitorias, Saldo, Gols sofridos, Gols feitos
        Ordenacao de sofridos crescente
        Ordenacao de pros descrescente
        Ordenacao de vitorias crescente
        Saldo é pros - contras
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "competicao.h"

int main()
{
    tCompeticao *jogo;
    torneio(jogo);
    ordenacao_torneio(jogo);
    libera_competicao(jogo);
    return 0;
}
