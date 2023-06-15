#include "lists.h"

/**
* get_dnodeint_at_index - writes node in a nth point
* @head: pointer
* @index: inode index
*
* Return: node / NULL
*
*
*
*
*
*
*
*
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int x;

	cur = head;
	x = 0;
	while (cur != NULL)
	{
		if (x == index)
			return (cur);
		cur = cur->next;
		x++;
	}
	return (NULL);
}
