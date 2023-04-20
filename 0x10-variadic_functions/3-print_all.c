#include "variadic_functions.h"
/**
*print_all - prints all types
*@format: type of argument
*@args: arguments
*@separator: separates
*/
void print_formatted(const char * const format, va_list args,
			const char *separator)
{
	unsigned int i = 0;
	char *s;

	while (format && format[i])
	{
		switch (format[i])
	{
	case 'c':
		printf("%c", va_arg(args, int));
		break;
	case 'i':
		printf("%d", va_arg(args, int));
		break;
	case 'f':
		printf("%f", va_arg(args, double));
		break;
	case 's':
		s = va_arg(args, char *);

		if (s == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", s);
		}
		break;
	}
	if (format[i + 1] != '\0' && (format[i] == 'c' || format[i] == 'i' ||
	 format[i] == 'f' || format[i] == 's'))
	{
		printf("%s", separator);
	}
	i++;
	}
}

void print_all(const char * const format, ...)
{
	va_list args;

	va_start(args, format);

	print_formatted(format, args, "");

	printf("\n");
	va_end(args);
}
