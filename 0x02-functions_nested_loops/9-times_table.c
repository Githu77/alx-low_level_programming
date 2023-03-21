#include "main.h"
/**
*times_table - prints multiplication table
*
*Return:returns 0
*/
void times_table(void)
{
int dig, mult, res;
for (dig = 0; dig <= 9; dig++)
{
_putchar('0');

for (mult = 1; mult <= 9; mult++)
{
_putchar(',');
_putchar(' ');
res = dig * mult;
if (res <= 9)
_putchar(' ');
else
_putchar((res / 10) + '0');

_putchar((res % 10) + '0');
}
_putchar('\n');
}
}
