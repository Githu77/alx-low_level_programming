#include <stdio.h>
#include <stdlib.h>
/**
*main - add +ve numbers
*@argc: arguments
*@argv: array of arguments
*Return: returns 0 or 1
*
*
*
*/
int main(int argc, char *argv[])
{
	int x = 1, y, add = 0;

	while (x < argc)
	{
	y = 0;

	while (argv[x][y] != '\0')
	{
		if (argv[x][y] < '0' || argv[x][y] > '9')
		{
		printf("Error\n");
		return (1);
		}
		y++;
	}

	add = add + atoi(argv[x]);
	x++;
	}

	printf("%d\n", add);

	return (0);
}

