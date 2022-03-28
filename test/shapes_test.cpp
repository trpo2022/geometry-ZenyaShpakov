#include <statlib/shapes.h>
#include <math.h>
#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, test1)
{
	double Arr_Cirle[3] = {0.0, 0.0, 1.5};
	double* Cir = CircleR(Arr_Cirle);
	double result = Cir[0];
	double expected = 9.420000;
	ASSERT_DBL_NEAR(expected, result);
}
CTEST(arithmetic_suite, test2)
{
	double Arr_Cirle[3] = {0.0, 0.0, 1.5};
	double* Cir = CircleR(Arr_Cirle);
	double result = Cir[1];
	double expected = 7.065000;
	ASSERT_DBL_NEAR(expected, result);
}
CTEST(arithmetic_suite, test3)
{	
	double Tria_Point[6] = {-3.0, -2.0, -1.0, 0.0, -3.0, -2.0};
	double* Tir = TriangleR(Tria_Point);
	double result = Tir[0];
	double expected = 9.656855;
	ASSERT_DBL_NEAR(expected, result);
}
CTEST(arithmetic_suite, test4)
{
	double Tria_Point[6] = {-3.0, -2.0, -1.0, 0.0, -3.0, -2.0};
	double* Tir = TriangleR(Tria_Point);
	double result = Tir[1];
	double expected = 4.000001;
	ASSERT_DBL_NEAR(expected, result);
}
