#include "main.h"
/**
*_memcpy - copies from a source and pastes in a destination
*@dest: the destination
*@src: the source
*@n: bytes to copy
*Return: returns the final string
*
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
