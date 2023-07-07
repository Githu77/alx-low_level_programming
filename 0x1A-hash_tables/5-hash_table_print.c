#include "main.h"

/**
* hash_table_print - write ht
* @ht: pointer
* Description: writes Key
*
*
*
*
*
*
*
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int x;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (x = 0; x < ht->size; x++)
	{
		if (ht->array[x] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[x];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
