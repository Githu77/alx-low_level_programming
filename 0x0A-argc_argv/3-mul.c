#include <stdio.h>
#include <stdlib.h>
/**
*main - prints multiple
*@argc: arguments
*@argv: arguments array
*Return: returns 0 or 1
*
*
*/

int main(int argc, char *argv[])
{
	int x, y, multiple;

	if (argc <= 2)
	{
		printf("Error\n");
		return (1);
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	multiple = x * y;

	printf("%d\n", multiple);
	return (0);
}
