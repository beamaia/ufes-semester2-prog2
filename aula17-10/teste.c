#define TAM 1000000000000000000
#include <stdlib.h>

int main()
{
    int *m = (int*) malloc(sizeof(int)*TAM*TAM*TAM*TAM*TAM*TAM*TAM*TAM*TAM*TAM*TAM*TAM);
    free(m);
    return 0;
}