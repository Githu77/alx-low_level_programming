#include "main.h"
/**
*_puts - prints a string
*@str: string to be printed
*Return: returns nothing
*
*/
void _puts(char *str)
{
	while (*str)
	{
		*str++;
		_putchar(*str);
	}
	_putchar('\n');
}
