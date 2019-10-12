#include <stdio.h>
#include <string.h>
#include "formas.h"
#include "terreno.h"

//Leitura do tipo de solo do terreno
void le_solo(tTerreno * t, FILE *fp)
{
    fscanf(fp, "%f ", &t->solo);
}

//Leitura do terreno de acordo com o seu tipo
void le_terreno(tTerreno *t, char tipo, FILE *fp)
{
    if(!strcmp(tipo, "triang"))
    {
        le_forma_triangulo(&t->forma, fp);
        strcpy(t->tag,"triang");
    }
    else if(!strcmp(tipo, "retang"))
    {
        le_forma_retangulo(&t->forma, fp);
        strcpy(t->tag, "retang");
    }
    else if(!strcmp(tipo, "trapez"))
    {
        le_forma_trapezio(&t->forma, fp)    ;
        strcpy(t->tag, "trapez");
    }
}

//Armazena area do terreno
void area_terreno(tTerreno *t)
{
    if(!strcmp(t->tag, "triang"))
    {
        t->area = area_forma_triangulo(&t->forma);
    }
    else if(!strcmp(t->tag, "retang"))
    {
        t->area = area_forma_retangulo(&t->forma);
    }
    else if(!strcmp(t->tag, "trapez"))
    {
        t->area = area_forma_trapezio(&t->forma);
    }
}

//Compara area de dois terrenos, se area1 < area2. Caso iguais, compara dois inteiros
int compara_area_terreno(tTerreno *t1, tTerreno *t2, int id1, int id2)
{
    if(t1->area < t2->area)
        return 1;
    
    if(t1->area == t2->area)
        return id1 < id2;
    
    return 0;
}