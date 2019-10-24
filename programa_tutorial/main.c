#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int *n = malloc(10 * sizeof(int));

    for(int i = 0; i < 30; i++)
    {
        if(i == 9)
        {
            n = realloc(n, 20 * sizeof(int));
        }
        n[i] = i;
    }
    return (EXIT_SUCCESS);
}

