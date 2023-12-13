#include "search_algos.h"

/**
* linear_search - search for value in array
* @array: integers array
* @size: array size
* @value: value
* Return: index value or -1
*
*
*
*
*
*
*
*/


int linear_search(int *array, size_t size, int value)
{
	size_t inc;

	if (array == NULL)
		return (-1);
	for (inc = 0; inc < size; inc++)
	{
		printf("Value checked array[%ld] = [%d]\n", inc, array[inc]);
		if (array[inc] == value)
			return (inc);
	}
	return (-1);
}
