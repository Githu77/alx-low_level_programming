#include "main.h"
/**
*_puts_recursion - prints string using recursion
*@s: the string
*Return: returns nothing
*
*
*
*/
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
	}
	else
	{
		_putchar(s[0]);
		_puts_recursion(s + 1);
	}
}
