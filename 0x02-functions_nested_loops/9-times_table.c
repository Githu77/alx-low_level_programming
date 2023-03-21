#include "main.h"
/**
*times_table - prints multiplication table
*
*Return:returns 0
*/
void times_table(void)
{
	int cons = 0;
	int mul = 0;
	int ans;

	while (cons <= 9)
	{
		while (mul <= 9)
		{
			ans = cons * mul;
			mul++;
			_putchar(ans);
		}
		cons++;
		_putchar('\n');
	}
}
