#include "main.h"
/**
*_strncat - concatenates two strings
*limited to the size of n
*@dest: the storage of string
*@src: the source of string
*@n: the size specifiers
*Return: returns the created string
*
*
*/
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;

	int j = 0;

	while (dest[i++])
		j++;

	for (i = 0; src[i] && i < n; i++)
		dest[j++] = src[i];

	return (dest);
}
