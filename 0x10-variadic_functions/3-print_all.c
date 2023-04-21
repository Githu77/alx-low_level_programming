#include "variadic_functions.h"


/**
 * print_char - Prints a char
 * @args: contain the char to print
 */
void print_char(va_list *args)
{
	int c = va_arg(*args, int);

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
	float f = va_arg(*args, double);

	printf("%f", f);
}

/**
 * print_string - Prints a string
 * @args: contain the string to print
 */

void print_string(va_list *args)
{
  char *s = va_arg(*args, char *);

  s = (s == NULL) ? "(nil)" : s;

  printf("%s", s);
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
