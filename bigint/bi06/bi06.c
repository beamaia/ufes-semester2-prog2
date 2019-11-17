#include <stdio.h>
#include <string.h>
#define MAX_NUM 100

typedef struct{
    char num[MAX_NUM + 1];
    int tam;
} Int_Grande;

Int_Grande inicializa_int_grande()
{
    Int_Grande n;
    for(int i = 0; i < 100; i++)
    {
        n.num[i] = 0;
    }

    n.tam = 0;
    return n;
}

Int_Grande le_int_grande()
{
    Int_Grande n;
    char aux;
    n = inicializa_int_grande();

    for(int i = 0; i < MAX_NUM; i++)
    {
        scanf("%c", &aux);
        if(aux >= '0' && aux <= '9')
        {
            n.num[i] = aux;
            n.tam++;
        }
        else
            break;
    }

    return n;
}

Int_Grande transforma_numero(Int_Grande n)
{
    for(int i = 0; i < n.tam; i++)
    {
        n.num[i] = n.num[i] - '0';
    }

    return n;
}

Int_Grande inverte_numeros(Int_Grande n)
{
    int aux;
    for(int i = 0; i < n.tam/2; i++)
    {
        aux = n.num[i];
        n.num[i] = n.num[n.tam - i - 1];
        n.num[n.tam - i - 1] = aux;
    }
    return n;
}

Int_Grande copia_numero(Int_Grande n1, Int_Grande n2)
{
    for(int i = 0; i < n1.tam; i++)
    {
        n2.num[i] = n1.num[i];
    }

    n2.tam = n1.tam;
    return n2;
}

Int_Grande soma_numeros(Int_Grande n1, Int_Grande n2)
{
    for(int i = 0; i < n2.tam; i++)
    {
        n2.num[i] += n1.num[i];

        if(n2.num[i] > 9)
        {
            n2.num[i + 1] += n2.num[i]/10;
            n2.num[i] = n2.num[i] % 10;
            if(i == n2.tam - 1)
                n2.tam++;
        }
    }
    return n2;
}

Int_Grande anula_num(Int_Grande n)
{
    n.num[0] = 0;
    n.tam = 1;
    return n;
}

Int_Grande multiplica_numeros(Int_Grande n, int mul)
{
    Int_Grande aux;
    aux = inicializa_int_grande();
    aux = copia_numero(n, aux);

    for(int i = 1; i < mul; i++)
    {
        n = soma_numeros(aux, n);
    }

    return n;
}

Int_Grande fatorial_numero(int mul)
{
    Int_Grande n;
    n = inicializa_int_grande();
    n.num[0] = 1;
    n.tam = 1;

    if(mul == 0 || mul == 1)
        return n;

    for(int i = 1; i < mul; i++)
    {
        n = multiplica_numeros(n, i + 1);
    }

    return n;
}


void apresenta_int_grande(Int_Grande n)
{
    for(int i = 0; i < n.tam; i++)
    {
        printf("%d", n.num[i]);
    }
    printf("\n");
}

int main()
{
    Int_Grande num;
    int mul;

    while(1)
    {
        scanf("%d", &mul);
        if(mul < 70)
            break;
    }

    num = fatorial_numero(mul);
    num = inverte_numeros(num);
    apresenta_int_grande(num);

    return 0;
}

