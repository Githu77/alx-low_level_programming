#include "main.h"
/**
*_strpbrk - locates first occurence of a string
*@s: string to search
*@accept: destination of bytes
*Return: returns byte to s
*
*/

char *_strpbrk(char *s, char *accept)
{
	int i;

	for (; *s != '\0'; s++)
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (accept[i] == *s)
			{
				return (s);
			}
		}
	}
	return ('\0');
}
