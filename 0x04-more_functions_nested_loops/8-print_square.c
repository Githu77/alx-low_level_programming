#include "main.h"
/**
*print_square - prints a square
*@size: gets size(width)
*/
void print_square(int size)
{
	int sq1;

	if (size > 0)
	{
		for (sq1 = 0; sq1 < size; sq1++)
		{
			int sq2;

			for (sq2 = 0; sq2 < (size - 1); sq2++)
			_putchar('#');

			_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
