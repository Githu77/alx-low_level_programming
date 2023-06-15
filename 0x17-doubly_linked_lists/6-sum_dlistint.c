#include "lists.h"

/**
*  sum_dlistint - adds elements
* the data (n) of a dlistint_t linked list.
* @head: pointer
*
* Return: 0 while empty
*
*
*
*
*
*
*
*/

int sum_dlistint(dlistint_t *head)
{

	int add = 0;
	dlistint_t *x;

	for (x = head; x != NULL; x = x->next)
	{
		add += x->n;
	}

	return (add);
}
