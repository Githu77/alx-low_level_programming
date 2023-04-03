#include "main.h"
/**
*_memset - fills memory with constant byte
*@s: the memory area
*@b: the substite byte
*@n: number of bytes to sub
*Return: returns substituted string
*/

char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; i = n; i++)
		s[i] = b;

	return (s);
}
