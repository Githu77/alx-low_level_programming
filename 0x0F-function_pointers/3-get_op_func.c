#include "3-calc.h"
/**
*get_op_func - chooses function to be executed
*@s: operator
*Return: pointer to selected function
*
*
*
*
*
*
*/
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (*(ops[i].op) == *s)
		{
			return (ops[i].f);
		}
	}
	return (NULL);
}
