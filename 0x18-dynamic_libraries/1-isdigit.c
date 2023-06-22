#include "main.h"
/**
*_isdigit - checks if c is digit or not
*@c: character in question
*Return: returns 1 if c is digit or 0 if not
*/
int _isdigit(int c)
{
	for (c = 0; c <= 9; c++)
	{
		if ((c >= 'a' || c <= 'z') && (c >= 'A' || c <= 'Z'))
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
}
