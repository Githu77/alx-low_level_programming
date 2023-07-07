#include "hash_tables.h"

/**
* key_index - index to store hash table
* @key: key to index
* @size: array size
* Return: index
* Description: djb2 algorithm.
*
*
*
*
*
*
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
