#include  "3-calc.h"
#include <stdio.h>
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
int main(int argc, char *argv[])
{
	int num1, num2, result;
	char op;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	op = *argv[2];

	result = calculate(num1, num2, op);

	printf("%d\n", result);
	return (0);
}

/**
*calculate - handles different operators
*@num1: first number
*@num2: second number
*@op: option selected
*Return: result or error
*
*
*
*/
int calculate(int num1, int num2, char op)
{
	switch (op)
	{
		case '+':
			return (num1 + num2);
		case '-':
			return (num1 - num2);
		case '*':
			return (num1 * num2);
		case '/':
		if (num2 == 0)
		{
			printf("Error\n");
			exit(100);
		}
		return (num1 / num2);
		case '%':
		if (num2 == 0)
		{
			printf("Error\n");
			exit(100);
		}
		return (num1 % num2);
		default:
		    printf("Error\n");
		    exit(99);
	}
}
