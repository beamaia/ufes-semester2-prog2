#include <stdio.h>
#include <stdlib.h>
#include "spec.h"
#include "catalog.h"
#include "properties.h"
#include "category.h"
#include "house.h"
#include "apt.h"
#include "lot.h"
#include "lot_category.h"
#include "triangle.h"
#include "rectangle.h"
#include "trapezoid.h"

///home/2019107651/ufes/semester-2/prog2b/trab1/validacao/1

int main()
{
    char arq_path1[150], arq_path2[150], arq_path3[150];
    scanf("%s", arq_path1);
    FILE *arc_cat = fopen(arq_path1, "r");
    scanf("%s", arq_path2);
    FILE *arc_current = fopen(arq_path2, "r");
    scanf("%s", arq_path3);
    FILE *arc_spec = fopen(arq_path3, "r");

    if(arc_cat == NULL || arc_current == NULL || arc_spec == NULL)
    {
        printf("Um dos arquivos não foi encontrado\n");
        exit(1);
    };

    Catalog properties, clayey, houses;
    Spec spec;
    Identifiers id;

    properties = initialize_catalog();
    read_catalog(properties, arc_cat);
    read_current(properties, arc_current);
    read_spec(&spec, arc_spec);
    initialize_identifiers(&id);


    if(are_there_properties(properties))
    {
        clayey = initialize_catalog();
        houses = initialize_catalog();
        area_catalog(properties);
        price_catalog(properties);
        sort_most_expensive_catalog(properties, &spec, &id);
        sort_creat_clayey_catalog(properties, clayey, &spec, &id);
        sort_create_houses_catalog(properties, houses, &spec, &id);
        print_id_catalogs(properties, clayey, houses, &spec, &id);
        free_properties_informed(properties);
        free_catalog(clayey);
        free_catalog(houses);
    }

    free_catalog(properties);

    fclose(arc_cat);
    fclose(arc_current);
    fclose(arc_spec);
    return 0;
}