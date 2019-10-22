#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apartamento.h"
#include "categoria.h"
#include "imovel.h"
#include "catalogo.h"
#include "espec.h"

int main()
{
    FILE *arq_cat = fopen("1/catalogo.txt", "r");
    FILE *arq_atual = fopen("1/atual.txt", "r");
    FILE *arq_espec = fopen("1/espec.txt", "r");

    if(!arq_cat || !arq_atual || !arq_espec)
    {
        printf("Arquivo não encontrado\n");
        exit(1);
    }

    tCatalogo imoveis, casas, argilosos;
    tEspec espec;
    tIdentificadores id;

    le_catalogo(&imoveis, arq_cat);
    le_atual(&imoveis, arq_atual);
    le_espec(&espec, arq_espec);
    imoveis_mais_caros(&imoveis, &espec, &id);
    terrenos_argilosos_menores(&imoveis, &argilosos, &id, &espec);
    casa_limite(&imoveis, &casas, &id, &espec);
    apresenta_catalogo(&imoveis, &argilosos, &casas);

    return 0;
}