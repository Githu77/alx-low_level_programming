#include "lists.h"
/**
*list_len - prints no of elements in  list
*@h: points to head of the list
*Return: no of nodes in list
*
*
*
*
*/

size_t list_len(const list_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		cnt++;
		h = h->next;
	}
	return (cnt);
}
