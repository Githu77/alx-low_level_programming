#include "lists.h"
/**
*pop_listint - deletes head node and returns its data
*@head: pointer to pointer to head node
*Return: returns deleted head node data
*
*
*
*
*
*
*/
int pop_listint(listint_t **head)
{
	int data;
	listint_t *tmp;

	if (head == NULL)
	{
		return (0);
	}

	tmp = *head;
	data = tmp->n;
	*head = (*head)->next;
	free(tmp);

	return (data);
}
