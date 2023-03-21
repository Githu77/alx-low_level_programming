#include "main.h"
#include <stdio.h>
/**
*_isalpha - checks for alphabets
*@c: the character being assessed
*Return: return 0 or 1
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	return (1);

	return (0);
}
