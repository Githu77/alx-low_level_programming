#include "main.h"
/**
*_isupper - checks whether uppercase or lowercase
*@c: the character in question
*Return: returns 1 if c is uppercase and 0 if otherwise
*/
int _isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
