#include "main.h"
#include <stdio.h>

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = 'A';
    printf("%c: %d\n", c, _isupper(c));
    c = 'a';
    printf("%c: %d\n", c, _isupper(c));
    return (0);
}

void print_numbers(void)
{
	int nums;

	for (nums = 0; nums <= 9; nums++)
	{
		_putchar(nums);
	}
	_putchar('\n');
}
