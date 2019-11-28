#include <stdio.h>
#include "house.h"

void read_house(House *house, FILE *arc)
{
    fscanf(arc, "%u%u%u%f%u%f%u", &house->rooms,
                                  &house->parking,
                                  &house->num_pav,
                                  &house->pav_area,
                                  &house->m2_price_pav,
                                  &house->outside_area,
                                  &house->m2_price_out);
}

void area_house(House * house)
{
    house->total_area = house->pav_area * house->num_pav;
}

float price_house(House *house)
{
    return (float) (house->m2_price_pav * house->total_area + house->m2_price_out * house->outside_area);
}

int check_house_area(House * house, float area_limit)
{
    if(house->total_area > area_limit)
        return 1;
    return 0;
}

int compare_room_quantity_house(House *house1, House *house2)
{
    if(house1->rooms < house2->rooms)
        return 1;
    if(house1->rooms == house2->rooms)
        return 2;
    return 0;
}