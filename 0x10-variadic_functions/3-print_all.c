#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a char
 * @args: contain the char to print
 */
void print_char(va_list *args)
{
	char c = va_arg(*args, int);

	printf("%c", c);
}

/**
 * print_int - Prints an int
 * @args: contain the int to print
 */
void print_int(va_list *args)
{
	int n = va_arg(*args, int);

	printf("%d", n);
}

/**
 * print_float - Prints a float
 * @args: contain the float to print
 */
void print_float(va_list *args)
{
	double f = va_arg(*args, double);

	printf("%f", f);
}

/**
 * print_string - Prints a string
 * @args: contain the string to print
 */
void print_string(va_list *args)
{
	char *s = va_arg(*args, char *);

	if (s == NULL)
	s = "(nil)";
	printf("%s", s);
}

/**
*print_all - prints all types
*@format: type of argument
*/
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;

	arg_printer_t arg_printers[] = {
	{'c', &print_char},
	{'i', &print_int},
	{'f', &print_float},
	{'s', &print_string},
	{0, NULL}
	};

	va_start(args, format);

	while (format[i])
	{
		j = 0;

		while (arg_printers[j].format)
		{
			if (format[i] == arg_printers[j].format)
			{
				arg_printers[j].printer(&args);
				break;
			}
			j++;
		}

		i++;
	}

	va_end(args);
}
