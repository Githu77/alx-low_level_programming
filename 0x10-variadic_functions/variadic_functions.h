#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>


/**
 * struct arg_printer - struct arg_printer
 * @specifier: specify character
 * @printer: pointer to function
 */
typedef struct arg_printer
{
	char specifier;
	void (*printer)(va_list *);
} arg_printer_t;

/* Function prototypes */
void print_char(va_list *args);
void print_int(va_list *args);
void print_float(va_list *args);
void print_string(va_list *args);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);


#endif
