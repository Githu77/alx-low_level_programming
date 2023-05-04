#include "main.h"
/**
*set_bit - sets value of bit to 1
*@n: pointer to where to change
*@index: beginning of bit to set
*Return: 1 or -1
*
*
*
*
*
*
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x = 1;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	x <<= index;
	*n |= x;

	return (1);
}
