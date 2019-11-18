#include <stdio.h>
#include <stdlib.h>
#define MAX_SEM 25;

typedef struct{
    int *agenda;
    int qtd_horas;
    int qtd_max;
} Agenda;

void zera_agenda(Agenda *a)
{
    for(int i = 0; i < a->qtd_max; i++)
    {
        a->agenda[i] = 0;
    }
}

Agenda inicializa_agenda()
{
    Agenda a;
    a.qtd_max = MAX_SEM
    a.qtd_horas = 0;
    a.agenda = (int *) malloc(sizeof(int) * a.qtd_max * 5 * 8);
    zera_agenda(&a);
    return a;
}

Agenda expande_agenda(Agenda *a)
{
    Agenda aux;
    aux.qtd_max = a->qtd_max + MAX_SEM;
    aux.qtd_horas = a->qtd_horas;

    aux.agenda = (int *) malloc(sizeof(int) * aux.qtd_max * 5 * 8);
    zera_agenda(&aux);

    for(int i = 0; i < aux.qtd_horas; i++)
    {
        aux.agenda[i] = a->agenda[i];
    }

    free(a->agenda);
    return aux;
}

Agenda le_agenda()
{
    Agenda a;
    char aux;
    int horas, i = 0;
    a = inicializa_agenda();

    scanf("%c", &aux);

    while((aux == '1' || aux == '0') && i < 10000)
    {
        if(i == a.qtd_max * 5 * 8 - 1)
            a = expande_agenda(&a);

        a.agenda[i] = aux;
        i++;

        scanf("%c", &aux);
    }

    a.qtd_horas = i;
    return a;
}

void transforma_agenda(Agenda *a)
{
    for(int i = 0; i < a->qtd_horas; i++)
    {
        a->agenda[i] -= '0';
    }
}

int hora_marcada(Agenda *a, int horas)
{
    int i, j, k = 0;
    for(i = 0; i < a->qtd_horas;)
    {
        j = i;
        for(i = i; i < 4 + j && i< a->qtd_horas;)
        {
            k = 0;
            while(a->agenda[i + k] == 0 && k < horas && (i + k) < (4 + j))
                k++;

            if(k == horas)
                return i+1;
            i++;
        }

    }

    return 0;
}
void apresenta_semana(int s)
{
    printf("Semana %d, ", s + 1);
}

void apresenta_dia(int d)
{
    switch(d)
    {
        case 0: printf("Segunda-feira, ");
                break;
        case 1: printf("Terça-feira, ");
                break;
        case 2:printf("Quarta-feira, ");
                break;
        case 3:printf("Quinta-feira, ");
                break;
        case 4:printf("Sexta-feira, ");
                break;
    }
}

void apresenta_hora(int h)
{
    if(h < 4)
    {
        printf("%d:00 horas\n", h + 8);
    }
    else
    {
        printf("%d:00 horas\n", h + 10);
    }
}

void apresenta_horario(int marcado)
{
    if(marcado == 0)
    {
        printf("Nao ha espaco na agenda para este compromisso!\n");
        return;
    }

    int semana, dia, hora;
    marcado--;
    semana = marcado / 40;
    dia = (marcado - 40 * semana) / 8;
    hora = marcado % 8;

    apresenta_semana(semana);
    apresenta_dia(dia);
    apresenta_hora(hora);
}

int main()
{
    Agenda agenda;
    int horas;
    int marcado;

    agenda = le_agenda();
    transforma_agenda(&agenda);
    scanf("%d", &horas);
    marcado = hora_marcada(&agenda, horas);
    apresenta_horario(marcado);

    return 0;
}