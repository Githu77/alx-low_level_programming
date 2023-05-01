#include "lists.h"
/**
*print_listint - prints all elements of a list
*@h: points to head of list
*Return: number of nodes in the list
*
*
*
*
*/
size_t print_listint(const listint_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		cnt++;
	}
	return (cnt);
}
