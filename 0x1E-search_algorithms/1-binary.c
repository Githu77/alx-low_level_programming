#include "search_algos.h"

/**
* binary_search - to search values
* @array: array
* @size: size
* @value: value
* Return: index value or -1
*
*
*
*
*
*
*
*
*/

int binary_search(int *array, size_t size, int value)
{

	size_t x, l, r;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		printf("Searching in array: ");
		for (x = l; x < r; x++)
			printf("%d, ", array[x]);
		printf("%d\n", array[x]);

		x = l + (r - l) / 2;
		if (array[x] == value)
			return (x);
		if (array[x] > value)
			r = x - 1;
		else
			l = x + 1;
	}

	return (-1);
}
