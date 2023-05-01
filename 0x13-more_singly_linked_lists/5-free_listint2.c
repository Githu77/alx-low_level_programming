#include "lists.h"
/**
*free_listint2 - frees list and sets head to NULL
*@head: points to pointer that points to head of list
*
*
*
*
*
*
*/
void free_listint2(listint_t **head)
{
	listint_t *first;
	listint_t **tmp = head;

	if (tmp != NULL)
	{
		if (*head == NULL)
		{
			return;
		}

		while (*head != NULL)
		{
			first = *head;
			*head = (*head)->next;
			free(first);
		}
		*tmp = NULL;
	}
}
