#include <stdio.h>
#include <math.h>
#define Size  2
#define pi 3.14
void Circle(float);
void Triangle(float*);
int main()
{
	int  count = 0, count_for_tria = 1;
	float radius, Tria_Point[6] = { 0 }, Size_of_Circle[4] = {0};
	printf("Inpur a radius: ");
	scanf("%f", &radius);
	printf("First object: circle\n");
	for (int i = 0; i < Size; i++)
	{
		float Number;
		if (i == 0)
		{
			printf("Input x: ");
			scanf("%f", &Number);
			Size_of_Circle[0] = Number + radius;
			Size_of_Circle[2] = Number - radius;
			
		}
		if (i == 1)
		{
			printf("Input y: ");
			scanf("%f", &Number);
			Size_of_Circle[1] = Number + radius;
			Size_of_Circle[3] = Number - radius;
		}
		
	}
	Circle(radius);
	printf("\nSecond object: triangle\n");
	for (int i = 0; i < Size * 3; i++)
	{
		float Number;
		
		if (i % 2 == 0)
		{
			printf("Input x%d: ", count_for_tria);
			scanf("%f", &Number);
			Tria_Point[i] = Number;		
		}
		if (i % 2 == 1)
		{
			printf("Input y%d: ", count_for_tria);
			scanf("%f", &Number);
			Tria_Point[i] = Number;	
			count_for_tria++;
		}		
	}
	Triangle(Tria_Point);	
	for (int j = 0; j < 6; j += 2)
	{
		if (Tria_Point[j] < Size_of_Circle[0] && Tria_Point[j] > Size_of_Circle[2])
		{
			if (Tria_Point[j+1] < Size_of_Circle[1] && Tria_Point[j+1] > Size_of_Circle[3]) count++;
		}
	}
	if ( count == 0 || count == 3) 
	{
		printf("\nTreugolnick peresekaet krug\n");
	}
	else
	{
		printf("peresechenia net\n");
	}
return 0;
}
void Circle(float radius)
{
	float Perim, Square;
	Perim = 2 * radius * pi;
	Square = pi * radius * radius;
	printf("Perimetr of circle: %f\n",Perim);
	printf("Squre of circle: %f\n",Square);
}
void Triangle(float Tria_Point[])
{
	float Perimetr = 0, storona_a = 0, storona_b = 0, storona_c = 0, Square = 0,  p;
	storona_a = sqrt(powf(Tria_Point[0] - Tria_Point[2], 2) + powf(Tria_Point[1]-Tria_Point[3], 2));
	storona_b = sqrt(powf(Tria_Point[0] - Tria_Point[4], 2) + powf(Tria_Point[1]-Tria_Point[5], 2));
	storona_c = sqrt(powf(Tria_Point[2] - Tria_Point[4], 2) + powf(Tria_Point[3]-Tria_Point[5], 2));
	Perimetr = storona_a + storona_b + storona_c;
	p = Perimetr / 2;
	Square = sqrt(p * (p -  storona_a ) * (p - storona_b) * (p - storona_c));
	printf("Perimetr of triangel: %f", Perimetr);
	printf("\nSquare of triangel: %f\n", Square);
}
