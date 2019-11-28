#include <stdio.h>
#include "apt.h"

/*
 * EN: Read apartment's information from a file.
 * PT: Le informacao do apartmento de um arquivo.
 */
void read_apartment(Apartment *apt, FILE *arc)
{
    fscanf(arc, "%u%u%u%f%u %c %u", &apt->rooms,
                                    &apt->parking,
                                    &apt->floor,
                                    &apt->area,
                                    &apt->m2_price,
                                    &apt->leisure_area,
                                    &apt->max_floor);

}

/*
 * EN: Returns apartment's price after calculating it.
 * PT: Retorna o preco do apartamento depois de o calcular.
 */

float price_apartment(Apartment *apt)
{
    switch (apt->leisure_area)
    {
        case 'S': return (float) ((0.9 + apt->floor/ apt->max_floor) * 1.15);
        case 'N': return (float) (0.9 + apt->floor/apt->max_floor);
        default: return 0;
    }
}