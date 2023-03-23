#include "main.h"
/**
*print_numbers - prints numbers from 0 to 9
*Return: returns 0
*
*/
void print_numbers(void)
{
	int nums;

	for (nums = 48; nums < 58; nums++)
	{
		_putchar(nums);
	}
	_putchar('\n');
}
