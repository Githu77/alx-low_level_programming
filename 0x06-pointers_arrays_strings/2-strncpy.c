#include "main.h"
/**
*_strncpy - copies a string
*@dest: storage of the string
*@src: source of string
*@n: number of bytes
*Return: returns string
*
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
