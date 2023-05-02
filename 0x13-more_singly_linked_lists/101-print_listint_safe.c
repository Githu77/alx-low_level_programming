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
	size_t cnt = 0;
	const listint_t *tmp, *check;

	if (head == NULL)
	{
		exit(98);
	}
	tmp = head;

	while (tmp != NULL)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		cnt++;
		check = tmp;
		tmp = tmp->next;
		if (check <= tmp)
		{
			printf("-> [%p] %d\n", (void *)tmp, tmp->n);
		}
	}
	return (cnt);
}
