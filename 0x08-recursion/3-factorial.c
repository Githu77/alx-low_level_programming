#include "main.h"
/**
*factorial - gives the factorial of an int
*@n: the int
*Return: returns 1 if n is equal to 0, or
*returns -1 if n is less than 0, or
*return the factorial of an int
*/
int factorial(int n)
{
	int i;

	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		i = factorial(n - 1);
		return (i * n);
	}
}
