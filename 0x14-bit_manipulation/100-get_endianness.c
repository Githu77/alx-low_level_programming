#include "main.h"
/**
*get_endianness - checks endianness of pc
*Return: 0 or 1
*
*
*
*
*
*
*
*
*/
int get_endianness(void)
{
	int x = 1;
	char *endian = (char *)&x;

	if (*endian == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
