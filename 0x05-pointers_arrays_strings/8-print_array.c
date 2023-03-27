#include "main.h"
#include <stdio.h>
/**
*print_array - prints elements of an array
*@a: the array
*@n: number of integers
*Return: returns nothing
*/
void print_array(int *a, int n)
{
	int inc;

	for (inc = 0; inc < n ; inc++)
	{
		if (inc != n - 1)
		{
			printf("%d, ", a[inc]);
		}
		else
		{
			printf("%d", a[inc]);
		}
	}
	printf("\n");
}
