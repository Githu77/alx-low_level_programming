#include <stdio.h>
/**
*main - prints number of arguments
*@argc: counts arguments
*@argv: array of arguments
*Return: returns nothing
*
*/
int main(int argc, char __attribute__((__unused__)) *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
