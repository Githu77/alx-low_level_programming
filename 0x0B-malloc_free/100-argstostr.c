#include "main.h"
/**
*argstostr - concatenates strings passed as arguments
*@ac: no of arguments
*@av: arguments passed
*Return: returns either NULL or pointer to string
*
*
*
*/
char *argstostr(int ac, char **av)
{
	int len, t_len = 0, cpy = 0;
	char *arg, *nstr;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (len = 0; len < ac; len++)
	{
		arg = av[len];
		while (*arg != '\0')
		{
			t_len++;
			arg++;
		}
		t_len++;
	}
	nstr = (char *) malloc(sizeof(char) * (t_len + 1));
	if (nstr == NULL)
	{
		return (NULL);
	}

	for (len = 0; len < ac; len++)
	{
		char *arg = av[len];

		while (*arg != '\0')
		{
			nstr[cpy] = *arg;
			arg++;
			cpy++;
		}
		nstr[cpy] = '\n';
		cpy++;
	}
	nstr[cpy] = '\0';

	return (nstr);
}
