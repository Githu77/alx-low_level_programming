#include "main.h"
#include <stddef.h>
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
	while (*haystack)
	{
		char *hay = haystack;

		char *need = needle;

		while (*hay == *need && *need != '\0')
		{
			hay++;
			need++;
		}

		if (*need == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
