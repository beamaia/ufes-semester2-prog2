#include <stdio.h>

typedef struct{
    float x, y, z;
} Vetor;

float dot(Vetor v1, Vetor v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

int main()
{
    Vetor v1, v2;
    scanf("%f%f%f%f%f%f", &v1.x, &v1.y, &v1.z, &v2.x, &v2.y, &v2.z);

    float resul;
    resul = dot(v1, v2);
    printf("%.1f", resul);
    return 0;
}