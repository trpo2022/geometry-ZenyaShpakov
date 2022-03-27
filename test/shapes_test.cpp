#include <statlib/shapes.h>
#include <math.h>
#include "ctest.h"

CTEST(arithmetic_suite, simple_sum)
{
	float Arr_Cirle[3] = {0.0, 0.0, 1.5};
	float* Cir = CircleR(Arr_Cirle);
	float result = Cir[0];
	float  expected = 2 * 3.14 * 1.5;
	ASSERT_EQUAL(expected, result);
	result = Cir[1];
	expected = 1.5 * 3.14 * 1.5;
	ASSERT_EQUAL(expected, result);

	float Tria_Point[6] = {-3.0, -2.0, -1.0, 0.0, -3.0, -2.0};
	float* Tir = TriangleR(Tria_Point);
	result = Tir[0];
	float storona_a = sqrt(powf(Tria_Point[0] - Tria_Point[2], 2) + powf(Tria_Point[1] - Tria_Point[3], 2));
        float storona_b = sqrt(powf(Tria_Point[0] - Tria_Point[4], 2) + powf(Tria_Point[1] - Tria_Point[5], 2));
	float storona_c = sqrt(powf(Tria_Point[2] - Tria_Point[4], 2) + powf(Tria_Point[3] - Tria_Point[5], 2));
	expected = storona_a + storona_b + storona_c;
	ASSERT_EQUAL(expected, result);
	float  polu = 0;
	polu = expected/2;
	result = Tir[1];
	expected = sqrt(polu * (polu - storona_a) * (polu - storona_b) * (polu - storona_c));
	ASSERT_EQUAL(expected, result);
}
