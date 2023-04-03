#include "main.h"
/**
*_strspn - gets length of prefix substring
*@s: the section in question
*@accept: the source
*Return: returns bytes number
*
*
*
*/

unsigned int _strspn(char *s, char *accept)
{
	int j = 0;

	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (accept[i] == *s)
			{
				j++;
				break;
			}
			else if ((accept[i + 1]) == '\0')
			{
				return (j);
			}
		}
		s++;
	}
	return (j);
}
