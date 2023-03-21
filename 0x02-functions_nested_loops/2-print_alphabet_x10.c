#include "main.h"
/**
*print_alphabet_x10 - prints the alphabet in lowercase 10 times;
*/
void print_alphabet_x10(void)
{
	char alphas;
	char times;

	for (times = '0'; times <= '9'; times++)
	{

		for (alphas = 'a'; alphas <= 'z'; alphas++)
		{
			_putchar(alphas);
		}
		_putchar('\n');
	}
}
