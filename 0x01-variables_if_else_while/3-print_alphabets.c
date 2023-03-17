#include <stdio.h>
#include <ctype.h>
/**
*main - Program to print alphabet letters
*
*Return: return 0
*/
int main(void)
{
	int alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		alpha = tolower(alpha);
		putchar(alpha);
		if (alpha == 'z')
		{
			for (alpha = 'A'; alpha <= 'Z'; alpha++)
			{
				putchar(alpha);
			}
			break;
		}
	}
	putchar('\n');
	return (0);
}
