#include "main.h"
/**
*print_most_numbers - print  0 - 9 omitting 2 and 4
*
*
*/
void print_most_numbers(void)
{
	int nums;

	for (nums = 48; nums < 58; nums++)
	{
		if ((nums == 50) || (nums == 52))
		{
			continue;
		}
		_putchar(nums);
	}
	_putchar(10);
}
