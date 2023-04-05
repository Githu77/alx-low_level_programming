#include "main.h"
/**
*_strlen_recursion - prints length of string
*@s: string to count
*Return: returns length of string
*
*
*/
int _strlen_recursion(char *s)
{
	int n = 0;

	if (*s != '\0')
	{
		n++;
		n = n + _strlen_recursion(s + 1);
	}
	return (n);
}
