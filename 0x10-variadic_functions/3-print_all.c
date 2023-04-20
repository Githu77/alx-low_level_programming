#include "variadic_functions.h"

/**
 * print_char - prints a char
 * @args: argument list containing a char
 *
 * Return: void
 */
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
 * print_int - prints an integer
 * @args: argument list containing an integer
 *
 * Return: void
 */
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}

/**
 * print_float - prints a float
 * @args: argument list containing a float
 *
 * Return: void
 */
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
 * print_string - prints a string
 * @args: argument list containing a string
 *
 * Return: void
 */
void print_string(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);

	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}


/**
*print_all - prints all types
*@format: type of argument
*/

void print_all(const char * const format, ...)
{
	va_list args;

	arg_printer_t arg_printers[] = {
	{'c', &print_char},
	{'i', &print_int},
	{'f', &print_float},
	{'s', &print_string},
	{'\0', NULL}
	};

	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		int j = 0;

		while (arg_printers[j].type != '\0')
		{
			if (format[i] == arg_printers[j].type)
			{
				arg_printers[j].printer(&args);
				if (format[i + 1] != '\0')
				{
					printf(", ");
				}
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");

	va_end(args);
}
