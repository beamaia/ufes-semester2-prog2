#include <stdio.h>

int leitura(int *);
void troca(int *, int);
void print_resultado(int *, int);

int main()
{
    int a[100], nums;

    nums = leitura(a);
    troca(a, nums);
    print_resultado(a, nums);

    return 0;
}

int leitura(int * a)
{
    int i, nums = 0;
    for(i = 0; i < 100; i++)
    {
        scanf("%d", &a[i]);
        nums++;
        if(a[i] == 0)
            break;
    }
    return nums;
}

void troca(int * a, int nums)
{
    int houve_troca = 1;
    int j, aux; 
    int ult_pos, aux_ult_pos;
    ult_pos = nums - 1;

    while(houve_troca)
    {
        houve_troca = 0;
        for(j = 0; j < ult_pos; j++)
        {    
            if(a[j] > a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                houve_troca = 1;
                aux_ult_pos = j;
            }
        }

        ult_pos = aux_ult_pos;
    } 
}

void print_resultado(int * a, int nums)
{
    for(int i = 0; i < nums; i++)
        printf("%d ", a[i]);
}
