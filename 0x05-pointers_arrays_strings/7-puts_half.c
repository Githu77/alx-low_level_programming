#include "main.h"
/**
*puts_half - prints the second half of the
*string if number is not odd
*@str: string to assess
*Return: returns nothing
*/
void puts_half(char *str)
{
	int len = _strlen(str);

	if (len % 2 == 0)
	{
		len = len / 2;
	}
	else
	{
		len = (len + 1) / 2;
	}
	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	}
	_putchar('\n');
}


/**
*_strlen - counts length of string
*@s: string in question
*Return: returns length
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
