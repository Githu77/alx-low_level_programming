#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>



/**
*struct arg_printer- struct arg_printer_t
*@type: type of argument
*@printer: pointed to function
*/

typedef struct arg_printer
{
	char type;
	void (*printer)(va_list *);
} arg_printer_t;

void print_char(va_list *args);
void print_int(va_list *args);
void print_float(va_list *args);
void print_string(va_list *args);

void print_all(const char * const format, ...);

#endif
