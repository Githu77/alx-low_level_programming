#include "main.h"
/**
*print_triangle - prints triangles
*@size:size of triangle(length)
*/
void print_triangle(int size)
{
	int tr1;

	if (size > 0)
	{
		for (tr1 = 1; tr1 <= size; tr1++)
		{
			int tr2;

			for ((tr2 = size - tr1); tr2 > 0; tr2--)
			_putchar(' ');

			for (tr2 = 0; tr2 < tr1; tr2++)
			_putchar('#');

			if (tr1 == size)
			continue;

		_putchar('\n');
		}
	}
	_putchar('\n');
}
