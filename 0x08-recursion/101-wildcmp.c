#include "main.h"

/**
*wildcmp - compares two strings
*@s1: in question
*@s2: how to check
*Return: returns 1 if considered identical or 0 if not
*
*
*/
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		return (*s1 == '\0');
	}
	else if (*s2 == *s1)
	{
		return (*s1 != '\0' && wildcmp(s1 + 1, s2 + 1));
	}
	else if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}
	else
	{
		return (0);
	}

}
