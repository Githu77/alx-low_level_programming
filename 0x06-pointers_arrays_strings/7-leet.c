#include "main.h"
/**
* leet -  encode a string
*@str:string to encoded
*Return:returns encoded string
*/

char *leet(char *str)
{
	int i = 0, j;
	char leet[8] = {'O', 'L', '?', 'E', 'A', '?', '?', 'T'};

	while (str[++i])
	{
		for (j = 0; j <= 7; j)
		{
			if (str[i] == leet[j] ||
			 str[i] - 32 == leet[j])
				str[i] = j + '0';
		}
	}
	return (str);
}
