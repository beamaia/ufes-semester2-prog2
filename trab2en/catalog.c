#include <stdio.h>
#include <stdlib.h>
#include "spec.h"
#include "catalog.h"
#include "properties.h"
#include "category.h"
#include "lot.h"
#include "lot_category.h"
#include "triangle.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "house.h"
#include "apt.h"
#define MAX_PROP 50

struct catalog{
    Property *properties;
    int max_prop;
    int qt_prop;
};

Catalog initialize_catalog()
{
    Catalog c = (Catalog) malloc(sizeof(struct catalog));
    c->qt_prop = 0;
    c->max_prop = MAX_PROP;
    return c;
}

void expand_catalog(Catalog c)
{
    c->max_prop += MAX_PROP;
    Property *aux = (Property *) malloc(sizeof(Property) * c->max_prop);

    for(int i = 0; i < c->qt_prop; i++)
    {
        aux[i] = c->properties[i];
        free_property(c->properties[i]);
    }

    free(c->properties);
    c->properties = aux;
}

void read_catalog(Catalog c, FILE * arc)
{
    for(int i = 0; !feof(arc) && i < c->max_prop; i++)
    {
        if(c->qt_prop == c->max_prop)
            expand_catalog(c);

        c->properties[i] = initialize_property();
        if(read_property(c->properties[i], arc) && c->qt_prop < c->max_prop)
            c->qt_prop++;
    }
}

void include_in_catalog(Catalog c, Property aux)
{
    if(c->qt_prop < c->max_prop)
    {
        c->properties[c->qt_prop] = initialize_property();
        c->properties[c->qt_prop++] = aux;
    }
}

void modify_in_catalog(Catalog c, Property aux)
{
    for(int i = 0; i < c->qt_prop; i++)
    {
        if(compare_id_property(c->properties[i], aux) == 2)
        {
            change_property_info(c->properties[i], aux);
            return;
        }
    }
}

void remove_from_catalog(Catalog c, Property aux)
{
    for(int i = 0; i < c->qt_prop - 1 && c->max_prop; i++)
    {
        if(compare_id_property(c->properties[i], aux) == 2)
        {
            free_property(c->properties[i]);
            free_property(aux);
            for(int j = i; j < c->qt_prop - 1 && j < c->max_prop; j++)
            {
                c->properties[j] = c->properties[j + 1];
            }
            c->qt_prop--;
            return;
        }
    }
}

void read_current(Catalog c, FILE * arc)
{
    Property aux = initialize_property();
    char action;
    int id;

    for(int i = 0; i < c->max_prop && !feof(arc); i++)
    {
        fscanf(arc, "%c", &action);
        if(c->qt_prop == c->max_prop)
            expand_catalog(c);

        switch(action)
        {
            case 'i': read_property(aux, arc);
                      include_in_catalog(c, aux);
                      break;
            case 'a': read_property(aux, arc);
                      modify_in_catalog(c, arc);
                      break;
            case 'e': fscanf(arc, "%d", &id);
                      put_id(aux, id);
                      remove_from_catalog(c, aux);
                      break;
            default: return;
        }
    }
}

int are_there_properties(Catalog c)
{
    return c->qt_prop > 0;
}

void area_catalog(Catalog c)
{
    for(int i = 0; i < c->qt_prop; i++)
    {
        area_property(c->properties[i]);
    }
}

void price_catalog(Catalog c)
{
    for(int i = 0; i < c->qt_prop; i++)
    {
        price_property(c->properties[i]);
    }
}

void sort(Catalog c, int (*cmp)(Property, Property))
{
    Property aux;
    for(int i = 0; i < c->qt_prop - 1; i++)
    {
        for(int j = 0; j < c->qt_prop - i - 1; j++)
        {
            if((*cmp)(c->properties[j], c->properties[j + 1]))
            {
                aux = c->properties[j];
                c->properties[j] = c->properties[j + 1];
                c->properties[j + 1] = aux;
            }
        }
    }
}

int clayey_catalog_quantity(Catalog c, Spec *spec)
{
    return (int) spec->percent_expensive * c->qt_prop / 100;
}

int properties_catalog_quantity(Catalog c, Spec *spec)
{
    return (int) spec->percent_expensive * c->qt_prop / 100;
}

void create_clayey_catalog(Catalog src, Catalog dest, Spec * spec)
{
    for(int i = 0; i < src->qt_prop; i++)
    {
        if(check_if_property_clayey(src->properties[i]))
        {
            dest->properties[dest->qt_prop++] = src->properties[i];
        }
    }
}

void create_houses_catalog(Catalog src, Catalog dest, Spec *spec)
{
    for(int i = 0; i < src->qt_prop - 1; i++)
    {
        if(check_if_house_limit(src->properties[i], spec->price_limit, spec->area_limit))
            dest->properties[dest->qt_prop++] = src->properties[i];
    }
}

void sort_most_expensive_catalog(Catalog c, Spec *spec, Identifiers *id)
{
    if(!c->qt_prop)
        return;

    sort(c, compare_price_property);
    int limit = properties_catalog_quantity(c, spec);
    if(!(spec->i > c->qt_prop || spec->i == 0))
        id->i = get_id(c->properties[spec->i - 1 + c->qt_prop - limit]);
}

void sort_creat_clayey_catalog(Catalog src, Catalog dest, Spec *spec, Identifiers *id)
{
    create_clayey_catalog(src, dest, spec);
    if(!dest->qt_prop)
        return;

    sort(dest, compare_area_property);
    int limit = clayey_catalog_quantity(dest, spec);

    if(!(spec->j > dest->qt_prop || spec->j == 0))
        id->j = get_id(dest->properties[spec->j - 1 + dest->qt_prop - limit]);
}

void sort_create_houses_catalog(Catalog src, Catalog dest, Spec *spec, Identifiers *id)
{
    create_houses_catalog(src, dest, spec);
    if(!dest->qt_prop)
        return;

    sort(dest, compare_room_property);

    if(!(spec->k > dest->qt_prop || spec->k == 0))
        id->k = get_id(dest->properties[spec->k - 1]);
}

void print_id_expensive_or_clayey_properties(Catalog c, int limit, FILE *arc)
{
    for(int i = c->qt_prop - limit; i < c->qt_prop; i++)
    {
        print_id(c->properties[i], arc);
        if(i != c->qt_prop - 1)
            fprintf(arc,", ");
    }
    if(c->qt_prop)
        fprintf(arc, "\n");
}

void print_limit_houses(Catalog c, FILE *arc)
{
    for(int i = 0; i < c->qt_prop; i++)
    {
        print_id(c->properties[i], arc);
        if(i != c->qt_prop - 1)
            fprintf(arc,", ");
    }
    if(c->qt_prop)
        fprintf(arc, "\n");
}

void print_id_catalogs(Catalog cat, Catalog clayey, Catalog house, Spec * spec, Identifiers * id)
{
    FILE * arc_output = fopen("saida.txt", "w");

    if(arc_output == NULL)
    {
        printf("Arquivo saida.txt não criado.\n");
        exit(1);
    }

    fprintf(arc_output, "%d\n", id->i + id->j + id->k);
    print_id_expensive_or_clayey_properties(cat, properties_catalog_quantity(cat, spec), arc_output);
    print_id_expensive_or_clayey_properties(clayey, clayey_catalog_quantity(clayey, spec), arc_output);
    print_limit_houses(house, arc_output);

    fclose(arc_output);
}

void free_properties_informed(Catalog c)
{
    for(int i = 0; i < c->qt_prop; i++)
        free_property(c->properties[i]);
}

void free_catalog(Catalog c)
{
    free(c);
}
