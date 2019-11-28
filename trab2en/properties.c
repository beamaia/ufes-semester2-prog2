//
// Created by bea on 11/25/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "properties.h"
#include "category.h"
#include "lot.h"
#include "lot_category.h"
#include "triangle.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "house.h"
#include "apt.h"
#define MAX_NAME 41

struct property{
    Category cat;
    char *tag;
    char *property_owner;
    unsigned int id;
    float price;
};

int identify_category(Property prop)
{
    if(!strcmp(prop->tag, "triang"))
        return 1;
    if(!strcmp(prop->tag, "retang"))
        return 2;
    if(!strcmp(prop->tag, "trapez"))
        return 3;
    if(!strcmp(prop->tag, "casa"))
        return 4;
    if(!strcmp(prop->tag, "apto"))
        return 5;
    return 0;
}

Property initialize_property()
{
    Property prop = (Property) malloc(sizeof(struct property));
    prop->price = 0;
    prop->id = 0;
    return prop;
}

void free_property(Property prop)
{
    free(prop->property_owner);
    free(prop->tag);
    free(prop);
}

int read_property(Property prop, FILE *arc)
{
    char aux[7];
    char aux_name[MAX_NAME];

    if(fscanf(arc, "%s", aux))
    {
        prop->tag = (char *) malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(prop->tag, aux);

        if(fscanf(arc, "%u", &prop->id))
        {
            fscanf(arc, "%[^\n]", aux_name);
            prop->property_owner = (char *) malloc(sizeof(char) * (strlen(aux_name) + 1));
            strcpy(prop->property_owner, aux_name);
            read_category(&prop->cat, identify_category(prop), arc);
            return 1;
        }
    }

    return 0;
}

void change_property_info(Property prop1, Property prop2)
{
    if(identify_category(prop1))
        free_property(prop1);
    else
        free(prop1);
    prop1 = prop2;
}

void area_property(Property prop)
{
   area_category(&prop->cat, identify_category(prop));
}

void price_property(Property prop)
{
    prop->price = price_category(&prop->cat, identify_category(prop));
}

int compare_id_property(Property prop1, Property prop2)
{
    if(prop1->id > prop2->id)
        return 1;
    if(prop1->id == prop2->id)
        return 2;
    return 0;
}

int compare_room_property(Property prop1, Property prop2)
{
    if(compare_room_quantity_category(&prop1->cat, &prop2->cat, identify_category(prop1), identify_category(prop2)) == 2)
    {
        if(!compare_id_property(prop1, prop2))
            return 1;
    }
    return 0;
}

int compare_price_property(Property prop1, Property prop2)
{
    if(prop1->price > prop2->price)
        return 1;
    if(prop1->price == prop2->price)
    {
        if (compare_id_property(prop1, prop2) == 1)
            return 1;
    }

    return 0;
}

int compare_area_property(Property prop1, Property prop2)
{
    if(identify_category(prop1) < 4 && identify_category(prop1) > 0)
    {
        if(identify_category(prop2) < 4 && identify_category(prop2) > 0)
        {
            if(compare_area_category(&prop1->cat, &prop2->cat, identify_category(prop1), identify_category(prop2)) == 1)
                return 1;
            if(compare_area_category(&prop1->cat, &prop2->cat, identify_category(prop1), identify_category(prop2)) == 2)
            {
                if(compare_id_property(prop1, prop2) == 1)
                    return 1;
            }
        }
    }

    return 0;
}

int check_if_property_clayey(Property prop)
{
    return check_if_clayey_category(&prop->cat, identify_category(prop));
}

int check_if_house_limit(Property prop, float price_limit, float area_limit)
{
    if(identify_category(prop) == 4)
    {
        if(check_if_house_limit_category(&prop->cat, identify_category(prop), area_limit))
        {
            if(prop->price < price_limit)
                return 1;
        }
    }

    return 0;
}

void put_id(Property prop, unsigned int id)
{
    prop->id = id;
}

unsigned int get_id(Property prop)
{
    return prop->id;
}

void print_id(Property prop, FILE * arc)
{
    fprintf(arc, "%u", prop->id);
}


