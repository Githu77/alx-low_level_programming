#include "lists.h"
/**
*listint_len - Counts number of elements in linked list
*@h: Points to head node of the list
*Return: Number of elements in the list
*
*
*
*
*
*/
size_t listint_len(const listint_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		cnt++;
		h = h->next;
	}
	return (cnt);
}
