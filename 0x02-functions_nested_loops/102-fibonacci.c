#include <stdio.h>
/**
*main - prints out first 50
*fibonacci suit numbers
*Return: return 0
*/
int main(void)
{
	int nums;

	unsigned long num1 = 0, num2 = 1, num3;

	for (nums = 0; nums < 50; nums++)
	{
		num3 = num1 + num2;

		printf("%lu", num3);
		num1 = num2;

		num2 = num3;

		if (nums == 49)
			printf("\n");
		else
			printf(", ");

	}

	return (0);
}
