#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shapes.h"
#inclide "fileread.h"

void Circle(char cc[])
{
	int i = 0;
	float coordinate_to_circle_in_index[3] = {0};
	printf("%s\n", cc);
	while(cc[i] != '(')
	{
		i++;
	}
	int count = 0;
	while (cc[i] != ')')
	{
		if (cc[i] == '.')
		{
			coordinate_to_circle_in_index[count] = (cc[i-1] & 0x0F) + (0.1 * (cc[i+1] & 0x0F));
			count ++;
		}
		i++;
	}
	for ( int j = 0; j < 3; j++) printf("%f ", coordinate_to_circle_in_index[j]);
	printf("\n");
	CircleR(coordinate_to_circle_in_index);
}

void Triangle(char cc[])
{
	int i = 0;
	float coordinate_to_triangle_in_index[6] = {0}, c = 0;
	printf("%s", cc);
	while(cc[i] != '(')
	{
		i++;
	}
	int count = 0;
	while (cc[i] != ')')
	{
		if (cc[i] == '.')
		{
			coordinate_to_triangle_in_index[count] = (cc[i-1] & 0x0F) + (0.1 * (cc[i+1] & 0x0F));
			if(cc[i-2] == '-') coordinate_to_triangle_in_index[count] *= -1;
			count ++;
		}
		i++;
	}
	for ( int j = 0; j < 6; j++) printf("%f ", coordinate_to_triangle_in_index[j]);
	printf("\n\n");
	TriangleR(coordinate_to_triangle_in_index);
}

int main()
{
	char cc[100];
	FILE *fp;
	if((fp= fopen("haha.txt", "r"))==NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	while((fgets(cc, 256, fp))!=NULL)
	{
		if (cc[0] == 't') Triangle(cc);
		if (cc[0] == 'c') Circle(cc);
	}
	fclose(fp);
	return 0;
}










