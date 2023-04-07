#include <stdio.h>
/**
*main - prints number of arguments
*@argc: counts arguments
*@argv: array of arguments
*Return: returns nothing
*
*/
int main(int argc, char *argv[])
{
	int i;

	int y;

	for (i = 1; i < argc; i++)
	{
		y++;
	}
	printf("%d\n", y);
	return (0);
}
