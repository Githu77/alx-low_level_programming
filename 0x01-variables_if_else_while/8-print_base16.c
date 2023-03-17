#include <stdio.h>
#include <ctype.h>
/**
*main - Prints all single digits of base 16 followed by new line
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
		  digit = 'a';
			for (; digit <= 'f'; digit++)
			{
				putchar(digit);
			}
			break;
		}
	}
	putchar('\n');
	return (0);
}
