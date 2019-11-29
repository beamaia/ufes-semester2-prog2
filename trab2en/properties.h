#ifndef _PROPERTIES
    #define _PROPERTIES
    #include <stdio.h>
    #include "category.h"
    #include "lot.h"
    #include "lot_category.h"
    #include "triangle.h"
    #include "rectangle.h"
    #include "trapezoid.h"
    #include "house.h"
    #include "apt.h"

    typedef struct property * Property;

    int identify_category(Property);
    Property initialize_property();
    int read_property(Property, FILE *);
    void read_property_to_be_removed(Property prop, FILE *);
    void change_property_info(Property, Property);
    void area_property(Property);
    void price_property(Property);
    int compare_id_property(Property, Property);
    int compare_room_property(Property, Property);
    int compare_price_property(Property, Property);
    int compare_area_property(Property, Property);
    int check_if_property_clayey(Property);
    int check_if_house_limit(Property, float, float);
    void put_id(Property, unsigned int);
    unsigned int get_id(Property);
    void print_id(Property, FILE *);
    void free_property(Property);

#endif
