#include "main.h"
/**
*print_rev - returns string in reverse
*@s: string in question
*Return : nothing
*
*/
void print_rev(char *s)
{
	int len = 0;

	int ind = 0;

	len = _strlen(s);

	for (ind = len - 1; ind >= 0; ind--)
	{
		_putchar(s[ind]);
	}
	_putchar('\n');
}

/**
*_strlen - returns the length of the string
*@s: string in question
*Return: returns length of string
*
*/
int _strlen(char *s)
{
	int cnt, len;

	len = 0;

	for (cnt = 0; s[cnt] != '\0'; cnt++)
	len++;

	return (len);
}
