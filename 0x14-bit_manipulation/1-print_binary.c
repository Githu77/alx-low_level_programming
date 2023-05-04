#include "main.h"
/**
*print_binary - print binary representation of number
*@n: No to print
*
*
*
*
*
*
*
*/
void print_binary(unsigned long int n)
{
	unsigned int x = 1;

	while (x <= n >> 1)
	{
		x <<= 1;
	}

	while (x)
	{
		if (x & n)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
		x >>= 1;
	}
}
