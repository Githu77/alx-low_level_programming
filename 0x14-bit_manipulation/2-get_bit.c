#include "main.h"
/**
*get_bit - returns value of bit at given index
*@n: No with the bit
*@index: index of required bit
*Return: -1 or required bit
*
*
*
*
*
*/
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
