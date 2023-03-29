#include "main.h"
/**
*_strcat - concatinates two strings
*@dest: first string
*@src: second string
*Return: returns the concatinated string
*
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;

	int j = 0;

	while (dest[i++])
		j++;

	for (i = 0; src[i]; i++)
		dest[j++] = src[i];

	dest[j] = '\0';

	return (dest);
}
