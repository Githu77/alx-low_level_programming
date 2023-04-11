#include "main.h"
/**
*create_array - creates array
*@size: size of array
*@c: character to write
*Return: returns either 0, NULL or pointer to an array
*
*
*/
char *create_array(unsigned int size, char c)
{
	if (size == 0)
	{
		return (NULL);
	}

	char *array = malloc(sizeof(char) * size);

	if (array == NULL)
	{
		return (NULL);
	}

	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = c;
	}

	return (array);
}
