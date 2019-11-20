#include <stdio.h>

int main()
{
    int num, aux1, aux2, cont = 1, aux_cont = 1;
    int maior_seq = 0;
    char esp;

    scanf("%d", &num);

    aux1 = num;
    if(scanf("%d%c", &num, &esp) == 2)
    {
        aux2 = num;
        while (scanf("%d%c", &num, &esp) == 2)
        {
            if (cont == 1)
            {
                    cont++;
            }

            if(aux1 + aux2 == num)
                cont++;
            else {
                cont = 1;
            }

            aux1 = aux2;
            aux2 = num;

            if ((maior_seq == 0 || (cont > maior_seq && cont > 2))) {
                maior_seq = cont;
            }

            if (esp == '\n')
                break;
        }
    }

    if(maior_seq > 2)
        printf("%d", maior_seq);
    else
        printf("0");
    return 0;
}