#include "variadic_functions.h"
/**
*sum_them_all - adds all parameters
*@n: 1st parameter
*Return: sum of parameters or 0
*
*
*
*
*
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int add = 0;
	unsigned int i;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		add = add + va_arg(args, int);
	}
	va_end(args);

	return (add);
}
