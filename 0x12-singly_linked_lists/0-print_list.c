#include "lists.h"
/**
*print_list - prints a list's elements
*@h: points to head of list
*Return: returns no of nodes
*
*
*
*
*/
size_t print_list(const list_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}
		cnt++;
		h = h->next;
	}
	return (cnt);
}
