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
	char *s1 = s;

	while (n > 0)
	{
		*s1 = b;
		s1++;
		n--;
	}
	return (s);
}
