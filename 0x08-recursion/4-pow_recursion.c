#include "main.h"
/**
*_pow_recursion - raises an int to the power of another
*@x: int to be raised
*@y: int to raise by
*Return: returns either -1, 1 or int that is power of x raised by y
*
*
*/
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (_pow_recursion(x, y - 1) * x);
	}
}

