#include "main.h"
/**
*print_diagonal - prints a diagonal line
*@n:parameter used
*/
void print_diagonal(int n)
{
	int hyp;

	if (n > 0)
	{
		for (hyp = 0; hyp < n; hyp++)
	{
		int bl;

		for (bl = 0; bl < hyp; bl++)
		_putchar(' ');

		_putchar('\\');

		if (hyp == (n - 1))
		continue;
		_putchar('\n');
	}
	}
	_putchar('\n');
}
