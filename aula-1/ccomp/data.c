#include <stdio.h>
#include "data.h"

void leia_data(tData * data)
{
    scanf("%d/%d/%d%*c", &data->dia, &data->mes, &data->ano);
}

void pergunta_data()
{
    printf("Insira a data:\n");
}

int igualdade_data(tData data1, tData data2)
{
    return data1.dia == data2.dia && data1.mes == data2.mes;
}

int menor_data(tData data1, tData data2)
{
    if(data1.ano < data2.ano || 
    (data1.ano == data2.ano && data1.mes < data2.mes) || 
    (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia < data2.dia)) 
    {
        return 1;
    }
    else
        return 0;   
}

void apresenta_data(tData data)
{
    printf("%02d/%02d/%02d",data.dia, data.mes, data.ano);
}
