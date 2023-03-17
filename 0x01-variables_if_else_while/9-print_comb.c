#include <stdio.h>
#include <ctype.h>
/**
*main - Prints all single digits with , and space
*
*Return: returns 0
*/
int main(void)
{
	int dig;

	for (dig = '0'; dig <= '9'; dig++)
	{
		putchar(dig);
		if (dig == '9')
			continue;

		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
