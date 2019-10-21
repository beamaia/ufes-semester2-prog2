#include <stdio.h>
#include <string.h>
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
    FILE *arq_cat = fopen("1/catalogo.txt", "r"),
         *arq_atual = fopen("1/atual.txt", "r")
         *arq_espec = fopen("1/espec.txt", "r");

    if(!arq_cat || !arq_atual || !arq_espec)
    {
        printf("Arquivo não encontrado\n");
        exit(1);
    }

    tCatalogo imoveis, casas, argilosos;
    tEspec espec;
    tIdentificadores id;

    le_catalogo(&imoveis, cat);
    le_atual(&imoveis, atual);
    le_espec(&espec, )
    imoveis_mais_caros()
    terrenos_argilosos_menores(&imoveis, &argilosos, &id, &espec);
    casa_limite(&imoveis, &casa, &id, &espec);
}