#include <stdio.h>
#include <stdlib.h>

/**
*main - prints least coins required
*@argc: arguments
*@argv: arguments array
*Return: returns 1 or 0
*
*
*
*/

int main(int argc, char *argv[])
{
	int cents, coin = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);

	while (cents > 0)
	{
		coin++;
		if ((cents - 25) >= 0)
		{
			cents = cents - 25;
			continue;
		}
		else if ((cents - 10) >= 0)
		{
			cents = cents - 10;
			continue;
		}
		else if ((cents - 5) >= 0)
		{
			cents = cents - 5;
			continue;
		}
		else if ((cents - 2) >= 0)
		{
			cents = cents - 2;
			continue;
		}
		cents--;
	}

	printf("%d\n", coin);
	return (0);
}
