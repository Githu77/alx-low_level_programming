#include "main.h"
/**
*string_toupper - changes lowercases to uppercase
*@str: parameter
*Return: returns character
*/

char *string_toupper(char *str)
{
	int i = 0;

	while (str[i++])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}

	return (str);
}
