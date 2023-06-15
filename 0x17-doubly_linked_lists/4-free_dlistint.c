#include "lists.h"

/**
* free_dlistint - frees list.
* @head: pointer
*
*
*
*
*
*
*
*
*
*/

void free_dlistint(dlistint_t *head)
{

	while (head != NULL)
	{
		dlistint_t *next = head->next;

		free(head);
		head = next;
	}
}
