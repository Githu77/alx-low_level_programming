#include "lists.h"
/**
*reverse_listint - reverses a list
*@head: pointer to pointer to head
*Return: returns pointer to new head
*
*
*
*
*
*/
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
