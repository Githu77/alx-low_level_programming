#include "main.h"
/**
*_strdup - returns pointer to copied string
*@str: string to copy
*Return: returns either NULL or pointer to string
*
*
*
*
*/
char *_strdup(char *str)
{
	int length = 0;
	char *str1;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}

	while (length != '\0')
	{
		length++;
	}

	str1 = malloc(sizeof(char) * (length + 1));

	if (str1 == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= length; i++)
	{
		str1[i] = str[i];
	}

	return (str1);
}
