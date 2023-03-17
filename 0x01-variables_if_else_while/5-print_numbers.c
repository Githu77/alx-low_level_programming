#include<stdio.h>
#include<ctype.h>
/**
*main - Prints all single digits of base 10 followed by new line
*
*Return: returns 0
*/
int main(void)
{
	int num;

	for (num = '0'; num < '9'; num++)
	{
		putchar(num);
	}
	putchar('\n');
	return (0);
}
