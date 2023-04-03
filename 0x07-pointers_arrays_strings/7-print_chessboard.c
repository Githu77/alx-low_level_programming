#include "main.h"
/**
*print_chessboard - prints chessboard
*@a: contains characters
*Return: returns nothing
*
*
*
*/
void print_chessboard(char (*a)[8])
{
	int x = 0;

	int z;

	while (a[x][7])
	{
		z = 0;

		while (z < 8)
		{
			_putchar(a[x][z]);
			z++;
		}
		_putchar('\n');
		x++;
	}
}
