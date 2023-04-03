#include "main.h"
/**
*print_diagsums - print sum of two diagonals
*@a: 2d array to be added
*@size: size of array
*
*
*/
void print_diagsums(int *a, int size)
{
	int i;

	int  b = 0;

	int c = 0;

	for (i = 0; i < size * size; i += size + 1)
	{
		b += a[i];
	}

	for (i = size - 1; i < size * size - 1; i += size - 1)
	{
		c += a[i];
	}
	printf("%d %d \n", b, c);
}
