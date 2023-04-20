#include "variadic_functions.h"
/**
*print_all - prints all types
*@format: type of argument
*
*
*
*
*
*
*
*
*/
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char c_arg;
	int i_arg;
	float f_arg;
	char *s_arg;

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				c_arg = va_arg(args, int);
				printf("%c", c_arg);
				break;
			case 'i':
				i_arg = va_arg(args, int);
				printf("%d", i_arg);
				break;
			case 'f':
				f_arg = va_arg(args, double);
				printf("%f", f_arg);
				break;
			case 's':
				s_arg = va_arg(args, char *);
				if (s_arg == NULL)
				{
					printf("(nil)");
				}
				else
				{
					printf("%s", s_arg);
				}
				break;
			default:
				break;
		}
		if (format[i + 1] && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
		{
			printf(",");
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
