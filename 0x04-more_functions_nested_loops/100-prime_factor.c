#include <stdio.h>

/**
*main- prints the largest prime factor
*
*Return: returns 0
*/

int main(void)
{
	long num = 612852475143;

	int num1;

	while (num1++ < num / 2)
	{
		if (num % num1 == 0)
		{
			num /= 2;
			continue;
		}

		for (num1 = 3; num1 < num / 2; num1 += 2)
		{
			if (num % num1 == 0)
			num /= num1;

		}
	}
	printf("%ld\n", num);
	return (0);
}
