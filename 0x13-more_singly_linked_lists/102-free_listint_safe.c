#include "lists.h"
/**
*free_listint_safe - free linked list
*@h: Points to head of list
*Return: size of freed list
*
*
*
*
*
*/
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t cnt = 0;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}
	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		cnt++;
		next = current->next;
		free(current);
		if (next >= current)
			break;

		current = next;
	}
	return (cnt);
}
