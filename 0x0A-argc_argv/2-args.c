#include <stdio.h>
/**
*main - lists arguments
*@argc: arguments
*@argv: arguments array
*Return: returns 0
*
*
*
*/
int main(int argc, char *argv[])
{
	int x;

	for (x = 0; x < argc; x++)
	{
		printf("%s\n", argv[x]);
	}
	return (0);
}
