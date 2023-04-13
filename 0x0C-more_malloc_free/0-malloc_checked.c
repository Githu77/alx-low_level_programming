#include "main.h"
/**
*malloc_checked - allocates memory
*@b: size of memory required
*Return: returns pointer to start of address allocated
*
*
*
*
*/
void *malloc_checked(unsigned int b)
{
	void *point;

	point = malloc(b);
	if (point == NULL)
	{
		exit(98);
	}
	return (point);
}
