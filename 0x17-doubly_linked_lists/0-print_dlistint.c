#include "lists.h"
/**
* print_dlistint - writes all
* @h: pointer
* Return: no of  nodes
*
*
*
*
*
*
*/

size_t print_dlistint(const dlistint_t *h)
{

	int cnt = 0;

	if (h == NULL)
		return (cnt);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		cnt++;
	}

	return (cnt);
}
