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
	printf("%d\n", argc - 1);
	return (0);
}
