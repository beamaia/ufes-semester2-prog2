#include <stdio.h>

int main()
{
    float x;
    FILE * binario;
    binario = fopen("saida", "rb");
    fread(&x, sizeof(float), 1, binario);
    fclose(binario);

    printf("%.1f\n", x);
    return 0;
}
