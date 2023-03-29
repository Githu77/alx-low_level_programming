#include "main.h"
/**
*reverse_array - reverses an integer array
*@a: array
*@n: array number
*
*
*
*/
void reverse_array(int *a, int n)
{
	int rev, i;

	for (i = n - 1; i > n / 2; i--)
	{
		rev = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = rev;
	}
}
