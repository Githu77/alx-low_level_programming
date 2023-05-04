#include "main.h"
/**
*clear_bit - sets a bit to 0
*@n: pointer to bit
*@index: index of bit
*Return: 1 or -1
*
*
*
*
*
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	x = 1 << index;
	x = ~x;
	*n = *n & x;
	return (1);
}
