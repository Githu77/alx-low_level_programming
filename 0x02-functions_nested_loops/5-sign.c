#include "main.h"
/**
*print_sign - prints the sign of a number
*@n: the character being assessed
*Return: returns 1, 0 or -1
*/
int print_sign(int n)
{
	char great, less, equal;

	great = '+';

	less = '-';

	equal = '0';

	if (n > 0)
	{
		_putchar(great);
		return (1);
	}
	else if (n == 0)
	{
		_putchar(equal);
		return (0);
	}
	else
	{
		_putchar(less);
		return (-1);
	}
}
