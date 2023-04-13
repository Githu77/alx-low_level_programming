#include "main.h"
/**
*string_nconcat - jins two strings
*@s1: string one
*@s2: string two
*@n: number of chars to coppy from s2
*Return: returns NULL or pointer to new string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1len = 0, s2len = 0, i, j;
	char *nstr;

	if (s1 != NULL)
	{
		while (s1[s1len] != '\0')
		{
			s1len++;
		}
	}

	if (s2 != NULL)
	{
		while (s2[s2len] != '\0')
		{
			s2len++;
		}
	}

	nstr = malloc(sizeof(char) * (s1len + n + 1));
	if (nstr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < s1len; i++)
	{
		nstr[i] = s1[i];
	}
	for (j = 0; j < n && j < s2len; j++)
	{
		nstr[i + j] = s2[j];
	}
	nstr[i + j] = '\0';
	return (nstr);
}
