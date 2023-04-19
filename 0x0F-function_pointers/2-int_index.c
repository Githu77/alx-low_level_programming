#include "function_pointers.h"
/**
*int_index - function that will search for an integer
*@array: array of elements
*@size: no of elements in array
*@cmp: compares values
*Return: returns -1 if no match
*
*
*
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	while (i < size)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
