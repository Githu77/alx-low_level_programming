#include <stdio.h>
/**
*main - prints the sum of multiples of
*3 and 5 below 1024
*Return: returns 0
*/

int main(void)
{
	int nums, d7;

	for (nums = 1; nums <= 1023; nums++)
	{
		int d5 = nums % 5;

		int d3 = nums % 3;

		if (d5 == 0 || d3 == 0)
		{
			d7 = d7 + nums;
		}
	}
	printf("Numbers are %d\n", d7);
	return (0);
}
