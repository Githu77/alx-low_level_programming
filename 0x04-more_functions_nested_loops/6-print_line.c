#include "main.h"
/**
*print_line - prints _ in given times
*@n: the number in question
*/
void print_line(int n)
{
	while (n-- > 0)
	{
		_putchar('_');
	}
	_putchar('\n');
}
