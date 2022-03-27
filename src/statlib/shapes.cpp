#include "shapes.h"
#include <math.h>
#include <stdio.h>
#define pi 3.14
#define Size 2

float *CircleR(float Arr_Circle[])
{
    float *Array_For_Shapes = new float[2];
    float PerimCir, SquareCir;
    PerimCir = 2 * Arr_Circle[2] * pi;
    SquareCir = pi * Arr_Circle[2] * Arr_Circle[2];
    printf("Perimetr of circle: %f\n", PerimCir);
    printf("Squre of circle: %f\n", SquareCir);
    Array_For_Shapes[0] = PerimCir;
    Array_For_Shapes[1] = SquareCir;
    printf("Perimeter of circl e%f\n", Array_For_Shapes[0]);
    return Array_For_Shapes;
    delete Array_For_Shapes;
}

float  *TriangleR(float Tria_Point[])
{
    float *Array_For_Shapes = new float[2];
    float PerimetrTR = 0, storona_a = 0, storona_b = 0, storona_c = 0, SquareTR = 0, p;
    storona_a = sqrt(powf(Tria_Point[0] - Tria_Point[2], 2) + powf(Tria_Point[1] - Tria_Point[3], 2));
    storona_b = sqrt(powf(Tria_Point[0] - Tria_Point[4], 2) + powf(Tria_Point[1] - Tria_Point[5], 2));
    storona_c = sqrt(powf(Tria_Point[2] - Tria_Point[4], 2) + powf(Tria_Point[3] - Tria_Point[5], 2));
    PerimetrTR = storona_a + storona_b + storona_c;
    p = PerimetrTR / 2;
    SquareTR = sqrt(p * (p - storona_a) * (p - storona_b) * (p - storona_c));
    printf("Perimetr of triangel: %f", PerimetrTR);
    printf("\nSquare of triangel: %f\n", SquareTR);
    Array_For_Shapes[0] = PerimetrTR;
    Array_For_Shapes[1] = SquareTR;
    return Array_For_Shapes;
    delete Array_For_Shapes;sqrt(powf(Tria_Point[0] - Tria_Point[2], 2) + powf(Tria_Point[1] - Tria_Point[3], 2));
}
