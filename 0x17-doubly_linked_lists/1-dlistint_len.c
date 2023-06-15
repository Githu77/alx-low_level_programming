#include "lists.h"

/**
* dlistint_len - prints no of elements
* @h: pointer
* Return: no of nodes
*
*
*
*
*
*
*
*/

size_t dlistint_len(const dlistint_t *h)
{
	int cnt = 0;

	if (h == NULL)
		return (cnt);

	while (h != NULL)
	{
		cnt++;
		h = h->next;
	}

	return (cnt);
}
