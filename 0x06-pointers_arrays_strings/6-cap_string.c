#include "main.h"
/**
*cap_string - capitalize 1st letter
*@str: string in question
*Return: returns capitalized string
*/
char *cap_string(char *str)
{
	int len, j;
	char sep[13] = {' ', '\t', '\n', ',', ';', '.', '!',
		'?', '"', '(', ')', '{', '}'};

	for (len = 0; str[len] != '\0'; len++)
	{
		if (len == 0 && str[len] >= 97 && str[len] <= 122)
			str[len] -= 32;

		for (j = 0; j < 13; j++)
			if (str[len] == sep[j])
				if (str[len + 1] >= 97 && str[len + 1] <= 122)
					str[len + 1] -= 32;
	}
	return (str);
}
