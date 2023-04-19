#include "function_pointers.h"
/**
*array_iterator - execute function given as parameter on each element
*@array: array in question
*@size: array size
*@action: function to execute
*
*
*
*
*
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i;

	if (action == NULL || array == NULL)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		actio(array[i]);
	}
}
