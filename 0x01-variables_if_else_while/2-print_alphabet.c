#include<stdio.h>
#include <ctype.h>
/**
*main - Program to print alphabet letter followed by new line
*
*Return: return 0
*/
int main(void)
{
int alpha;
for(alpha = 'a'; alpha <= 'z'; alpha++)
{
	alpha = tolower(alpha);
	putchar(alpha);
}
putchar('\n');
return (0);
}
