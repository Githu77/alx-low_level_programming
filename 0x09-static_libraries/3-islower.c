#include "main.h"
#include <stdio.h>

/**
 *_islower - checks for lowercase character
 *@c: is checked for lowercase character
 *Return: returns 0 or 1
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	return (1);

	return (0);
}
