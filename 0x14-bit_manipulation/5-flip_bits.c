#include "main.h"
/**
*flip_bits - returns no of bits required to flip in order
*to get to another no
*@n: 1st number
*@m: 2nd number
*Return: number of bits flipped
*
*
*
*
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xres = n ^ m;
	unsigned int bits = 0;

	while (xres > 0)
	{
		bits += xres & 1;
		xres >>= 1;
	}
	return (bits);
}
