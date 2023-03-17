#include <stdio.h>
#include <ctype.h>
/**
*main - Prints all single digits of base 16
*
*Return: returns 0
*/
int main(void)
{
	int dig;

	for (dig = 0; dig <= 9; dig++)
	{
		putchar(dig);
		if (dig == '9')
		{
		  dig = 'a';
			for (; dig <= 'f'; dig++)
			{
				putchar(dig);
			}
			break;
		}
	}
	putchar('\n');
	return (0);
}
