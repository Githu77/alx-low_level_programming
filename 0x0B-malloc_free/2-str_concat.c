#include "main.h"
/**
*str_concat - concatenates two strings
*@s1: 1st string
*@s2: 2nd string
*Return: returns NULL or concatenated string
*
*
*
*/
char *str_concat(char *s1, char *s2)
{
	char *newstring;
	int i, length, s1length = 0, s2length = 0, s1_s2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (i = 0; s1[i]; i++)
	{
		s1length++;
	}
	for (i = 0; s2[i]; i++)
	{
		s2length++;
	}
	length = s1length + s2length + 1;

	newstring = malloc(sizeof(char) * (length));

	if (newstring == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i]; i++)
	{
		newstring[s1_s2++] = s1[i];
	}
	for (i = 0; s2[i]; i++)
	{
		newstring[s1_s2++] = s2[i];
	}
	return (newstring);
}
