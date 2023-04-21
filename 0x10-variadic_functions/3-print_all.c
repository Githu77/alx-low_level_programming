#include "variadic_functions.h"
#include <string.h>
#include <stdio.h>

/**
 * print_all - prints all types
 * @format: type of argument
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", separator, va_arg(args, int));
		}
		else if (format[i] == 'i')
		{
			printf("%s%d", separator, va_arg(args, int));
		}
		else if (format[i] == 'f')
		{
			printf("%s%f", separator, va_arg(args, double));
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(args, char *);

			printf("%s%s", separator, s ? s : "(nil)");
		}
		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}

