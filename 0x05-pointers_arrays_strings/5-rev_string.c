#include "main.h"
/**
*rev_string - reverses a string
*@s: string in question
*Return: returns nothing
*
*/
void rev_string(char *s)
{
	int i = 0,

	len;

	len = _strlen(s) - 1;

	while (len > i)
	{
		swap_char(s + len, s + i);
		i++;
		len--;
	}
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

/**
*swap_char - swaps the content of the pointers
*@a: first pointer
*@b: second pointer
*Return : returns nothing
*
*/
void swap_char(char *a, char *b)
{
	char ch = *a;
	*a = *b;
	*b = ch;
}
