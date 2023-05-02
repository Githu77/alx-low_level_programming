#include "lists.h"
/**
*print_listint_safe - prints linked list
*@head: pointer to head of list
*Return: No. of nodes in the list
*
*
*
*
*
*
*/
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *curr = head, *next;

	while (curr != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)curr, curr->n);
		next = curr->next;
		if (next >= curr)
		{
			printf("-> [%p] %d\n", (void *)next, next->n);
			break;
		}
		curr = next;
	}

	if (curr == NULL)
	return (count);

	exit(98);
}
