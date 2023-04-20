#include "3-printall.h"


/**
*print_char - prints character
*@args: arguments
*
*
*/
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
*print_int - prints integer
*@args: arguments
*
*
*/
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}

/**
*print_float - prints float
*@args: arguments
*
*
*/
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
*print_string - prints string
*@args: arguments
*
*
*/
void print_string(va_list *args)
{
	char *s = va_arg(*args, char *);

	if (s == NULL)
	{
		printf("(nil)");
	}
	else
	{
		printf("%s", s);
	}
}

/**
*print_all - prints all types
*@format: type of argument
*/

void print_all(const char * const format, ...)
{
	va_list args;

	va_start(args, format);

	arg_printer_t arg_printers[] = {
	{'c', &print_char},
	{'i', &print_int},
	{'f', &print_float},
	{'s', &print_string},
	{'\0', NULL}
	};

	int i = 0;

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
