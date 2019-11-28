#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int bank, agency, person;
    float operation;
} tAux;

typedef tAux * Aux;

Aux initialize_aux()
{
    Aux a;
    a = (Aux) malloc(sizeof(tAux));
    a->bank = a->agency = a->person = 0;
    a->operation = 0;
    return a;
}

int read_aux(Aux a)
{
    scanf("%u%u%u%f", &a->bank, &a->agency, &a->person, &a->operation);
    if(a->bank)
        return 1;
    return 0;
}

void free_aux(Aux a)
{
    free(a);
}

int main()
{
    Aux a = initialize_aux();

    while(read_aux(a))
    {
        read_aux(a);
    }

    return 0;
}