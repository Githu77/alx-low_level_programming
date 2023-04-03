#include "main.h"
/**
*_strchr - searches through string
*@s: string to search
*@c: cha to find
*Return: returns the found result or NULL
*
*
*
*/

char *_strchr(char *s, char c)
{
	int y;

	for (y = 0; (s[y] != c) && (s[y] != '\0'); y++)
	;
	{
		if (s[y] == c)
		{
			return (s + y);
		}
		else
		{
			return (NULL);
		}
	}
}
