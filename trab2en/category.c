#include <stdio.h>
#include "category.h"
#include "lot.h"
#include "lot_category.h"
#include "triangle.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "house.h"
#include "apt.h"

void read_category(Category *cat, int tag, FILE *arc)
{
    switch (tag)
    {
        case 1: read_lot(&cat->lot, tag, arc);
                break;
        case 2: read_lot(&cat->lot, tag, arc);
                break;
        case 3: read_lot(&cat->lot, tag, arc);
                break;
        case 4: read_house(&cat->house, arc);
                break;
        case 5: read_apartment(&cat->apt, arc);
                break;
        default: break;
    }
}

void area_category(Category *cat, int tag)
{
    switch (tag)
    {
        case 1: area_lot(&cat->lot, tag);
        case 2: area_lot(&cat->lot, tag);
        case 3: area_lot(&cat->lot, tag);
        case 4: area_house(&cat->house);
        default: return;
    }
}

float price_category(Category *cat, int tag)
{
    switch (tag)
    {
        case 1: return price_lot(&cat->lot);
        case 2: return price_lot(&cat->lot);
        case 3: return price_lot(&cat->lot);
        case 4: return price_house(&cat->house);
        case 5: return price_apartment(&cat->apt);
        default: return 0;
    }
}

int check_if_clayey_category(Category *cat, int tag)
{
    if(tag == 1 || tag == 2 || tag == 3)
        return is_lot_clayey(&cat->lot);
    return 0;
}

int check_if_house_limit_category(Category *cat, int tag, float limit)
{
    if(tag == 4)
        return check_house_area(&cat->house, limit);
    return 0;
}

int compare_room_quantity_category(Category *cat1, Category *cat2, int tag1, int tag2)
{
    if(tag1 == 4 && tag2 == 4)
        return compare_room_quantity_house(&cat1->house, &cat2->house);
    return 0;
}

int compare_area_category(Category *cat1, Category *cat2, int tag1, int tag2)
{
    if((tag1 == 1 || tag1 == 2 || tag1 == 3) && (tag2 == 1 || tag2 == 2 || tag2 == 3))
        return compare_area_lot(&cat1->lot, &cat2->lot);
    return 0;
}

