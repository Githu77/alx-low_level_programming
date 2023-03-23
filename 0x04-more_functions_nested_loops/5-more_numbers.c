#include "main.h"
/**
*more_numbers - prints numbers 0 -14 ten times
*
*/
void more_numbers(void)
{
	int nums, nums1;

	for (nums = 0; nums < 10; nums++)
	{
		int nums1;

		for (nums1 = 0; nums <= 14; nums++)
		{
			if (nums1 > 9)
			{
				_putchar((nums1 / 10) + '0');
			}
			else
			{
				_putchar((nums1 % 10) + '0');
			}
			_putchar(10);
		}
	}
}
