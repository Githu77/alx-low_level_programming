#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
*main - does add, subtract, division and multiplication
*@argc: no of commands
*@argv: array of commands
*Return: either 98 or 0
*
*
*
*
*/
int main(int argc, char **argv)
{
	int num1, num2, result;
	char *op;
	int (*f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	f = get_op_func(op);

	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	result = f(num1, num2);

	printf("%d\n", result);

	return (0);
}
