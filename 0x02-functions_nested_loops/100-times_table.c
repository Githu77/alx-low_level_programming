#include "main.h"
/**
*print_times_table - prints the  times table
*@n: parameter
*Return: null
*/
void print_times_table(int n)
{
int dig, mul, res;
if (n <= 15 && n >= 0)
{
for (dig = 0; dig <= n; dig++)
{
_putchar('0');

for (mul = 1; mult <= n; mult++)
{
_putchar(',');
_putchar(' ');
res = dig * mul;
if (res <= 99)
_putchar(' ');

if (res <= 9)
_putchar(' ');
if (res >= 100)
{
_putchar((res / 100) + '0');
_putchar((res / 10) % 10 + '0');
}
else if (res <= 99 && res >= 10)
{
_putchar((res / 10) + '0');
}
_putchar((res % 10) + '0');
}
_putchar('\n');
}
}
}
