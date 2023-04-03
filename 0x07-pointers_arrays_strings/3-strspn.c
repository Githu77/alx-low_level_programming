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
	int i = 0;

	unsigned int z = 0;

	while (s[i] != '\0')
	{
		int x = 0;

		while (accept[x] != '\0')
		{
			if (s[i] == accept[x])
			{
				z++;
				break;
			}
			x++;

			if (s[i] != accept[x])
			{
				return (z);
			}
		}
		i++;

	}
	return (z);
}
