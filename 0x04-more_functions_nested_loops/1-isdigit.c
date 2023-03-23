#include "main.h"
/**
*_isdigit - checks if c is digit or not
*@c: character in question
*Return: returns 1 if c is digit or 0 if not
*/
int _isdigit(int c)
{	
	int lis;
	
	for (lis = 0; lis <= 9; lis++)
	{
		if ((lis >= 'a' || lis <= 'z') || (lis >= 'A' || lis <= 'Z'))
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
}
