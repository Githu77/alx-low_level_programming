#include "function_pointers.h"
/**
*print_name - print name
*@name: name required
*@f: function that prints name
*
*
*
*
*
*
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULLL || f == NULL)
	{
		return;
	}
	f(name);
}
