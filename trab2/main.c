#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espec.h"
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"
#include "casa.h"
#include "apto.h"
#include "categoria.h"
#include "imovel.h"
#include "catalogo.h"

int main()
{
    char arq_path1[150], arq_path2[150], arq_path3[150];
    scanf("%s", arq_path1);
    FILE *arq_cat = fopen(arq_path1, "r");
    scanf("%s", arq_path2);
    FILE *arq_atual = fopen(arq_path2, "r");
    scanf("%s", arq_path3);
    FILE *arq_espec = fopen(arq_path3, "r");

    if(arq_cat == NULL || arq_atual == NULL || arq_espec == NULL)
    {
        printf("Arquivo não encontrado\n");
        exit(1);
    }

    tCatalogo imoveis, casas, argilosos;
    tEspec espec;
    tIdentificadores id;

    inicializa_catalogo(&imoveis);
    inicializa_catalogo(&casas);
    inicializa_catalogo(&argilosos);
    le_catalogo(&imoveis, arq_cat);
    le_atual(&imoveis, arq_atual);

    if(imoveis.qtd_imoveis)
    {
        inicializa_espec(&espec);
        le_espec(&espec, arq_espec);
        calcula_area(&imoveis);
        calcula_preco(&imoveis);
        imoveis_mais_caros(&imoveis, &espec, &id);
        terrenos_argilosos_menores(&imoveis, &argilosos, &id, &espec);
        casas_limite(&imoveis, &casas, &id, &espec);
    }
    apresenta_catalogos(&imoveis, &argilosos, &casas, &id, &espec);

    fclose(arq_atual);
    fclose(arq_cat);
    fclose(arq_espec);
    return 0;
}