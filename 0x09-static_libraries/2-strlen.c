#include "main.h"
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
