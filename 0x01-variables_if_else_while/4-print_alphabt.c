#include<stdio.h>
#include<ctype.h>
/**
*main - Program to print alphabet letters except q and e and new line
*
*Return: return 0
*/
int main(void)
{
	int alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		if (alpha == 'e' || alpha == 'q')
		{
			continue;
		}
	putchar(alpha);
	}
	putchar('\n');
	return (0);
}
