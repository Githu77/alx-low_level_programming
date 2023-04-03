#include "main.h"
/**
*_strstr - finds first occurence of a string
*@haystack: string in question
*@needle: string to search
*Return: returns pointer to location of the string
*
*
*/
char *_strstr(char *haystack, char *needle)
{
	int i = 0;

	if (*needle == 0)
	{
		return (haystack);
	}
	else
	{
		for (; *haystack; haystack++)
		{
			while (haystack[i] == needle[i])
			{
				if (needle[i] == '\0')
				{
					return (haystack);
				}
				i++;
			}
		}
	return ('\0');
	}
}
