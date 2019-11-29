#ifndef _CATEGORY
    #define _CATEGORY
    #include <stdio.h>
    #include "lot.h"
    #include "lot_category.h"
    #include "triangle.h"
    #include "rectangle.h"
    #include "trapezoid.h"
    #include "house.h"
    #include "apt.h"

    typedef union{
        Lot lot;
        House house;
        Apartment apt;
    } Category;

    int read_category(Category *, int, FILE *);
    void area_category(Category *, int);
    float price_category(Category *, int);
    int check_if_clayey_category(Category *, int);
    int check_if_house_limit_category(Category *, int, float);
    int compare_room_quantity_category(Category *, Category *, int, int);
    int compare_area_category(Category *, Category *, int, int);

#endif

