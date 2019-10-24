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
    FILE *arq_cat = fopen("catalogo.txt", "r");
    FILE *arq_atual = fopen("atual.txt", "r");
    FILE *arq_espec = fopen("espec.txt", "r");

    if(!arq_cat || !arq_atual || !arq_espec)
    {
        printf("Arquivo não encontrado\n");
        exit(1);
    }

    tCatalogo imoveis, casas, argilosos;
    tEspec espec;
    tIdentificadores id;

    inicializa_catalogo(&imoveis);
    le_catalogo(&imoveis, arq_cat);
    le_atual(&imoveis, arq_atual);
    le_espec(&espec, arq_espec);
    calcula_area(&imoveis);
    calcula_preco(&imoveis);
    imoveis_mais_caros(&imoveis, &espec, &id);
    terrenos_argilosos_menores(&imoveis, &argilosos, &id, &espec);
    casas_limite(&imoveis, &casas, &id, &espec);
    apresenta_catalogos(&imoveis, &argilosos, &casas, &id, &espec);

    fclose(arq_atual);
    fclose(arq_cat);
    fclose(arq_espec);
    return 0;
}