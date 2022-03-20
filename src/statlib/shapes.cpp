#include "shapes.h"
#include <math.h>
#include <stdio.h>
#define pi 3.14
#define Size 2

void CircleR(float Arr_Circle[])
{
    float Perim, Square;
    Perim = 2 * Arr_Circle[2] * pi;
    Square = pi * Arr_Circle[2] * Arr_Circle[2];
    printf("Perimetr of circle: %f\n", Perim);
    printf("Squre of circle: %f\n", Square);
}

void TriangleR(float Tria_Point[])
{
    float Perimetr = 0, storona_a = 0, storona_b = 0, storona_c = 0, Square = 0, p;
    storona_a = sqrt(powf(Tria_Point[0] - Tria_Point[2], 2) + powf(Tria_Point[1] - Tria_Point[3], 2));
    storona_b = sqrt(powf(Tria_Point[0] - Tria_Point[4], 2) + powf(Tria_Point[1] - Tria_Point[5], 2));
    storona_c = sqrt(powf(Tria_Point[2] - Tria_Point[4], 2) + powf(Tria_Point[3] - Tria_Point[5], 2));
    Perimetr = storona_a + storona_b + storona_c;
    p = Perimetr / 2;
    Square = sqrt(p * (p - storona_a) * (p - storona_b) * (p - storona_c));
    printf("Perimetr of triangel: %f", Perimetr);
    printf("\nSquare of triangel: %f\n", Square);
}
