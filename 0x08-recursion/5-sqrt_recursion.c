#include "main.h"
/**
*_sqrt_recursion - square root of a number
*@n: given int
*Return: returns squareroot
*
*
*
*
*
*/
int _sqrt_recursion(int n)
{
	if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (_sqrt(0,n));
	}
}

/**
*_sqrt - squares a number
*@n: given int
*@i: the square
*Return: returns root of square
*
*
*
*/
int _sqrt(int n, int i)
{
	if (n > i / 2)
	{
		return (-1);
	}
	else if (n * n == i)
	{
		return (n);
	}
	else
	{
		return (_sqrt(n + 1, i));
	}
}
