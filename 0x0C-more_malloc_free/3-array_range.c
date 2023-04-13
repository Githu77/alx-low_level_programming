#include "main.h"
/**
*array_range - creates an array of type int
*@min: smallest int in array
*@max: largest int in array
*Return: reurns either null or pointer to arrays location
*
*
*
*/
int *array_range(int min, int max)
{
	int length, i;
	int *arry;

	if (min > max)
	{
		return (NULL);
	}

	length = max - min + 1;

	arry = (int *) malloc(sizeof(int) * length);

	if (arry == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)
	{
		arry[i] = min + i;
	}
	return (arry);
}
