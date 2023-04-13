#include "main.h"
/**
*_calloc - allocates memory and ensures is set to zero
*@nmemb: no of elements
*@size: size of memory required
*Return: NULL or pointer to created memory
*
*
*
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *point;
	int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	point = malloc(nmemb * size);

	if (point == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < nmemb * size; i++)
	{
		point[i] = 0;
	}
	return point;
}
