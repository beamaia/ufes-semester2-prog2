#include <stdio.h>

int main()
{
    float x = 37.6; 

    FILE * binario;
    binario = fopen("saida", "wb");
    fwrite(&x, sizeof(float), 1, binario);
    fclose(binario);
    return 0;
}
