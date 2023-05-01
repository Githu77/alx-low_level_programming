#include "lists.h"
/**
*sum_listint - adds all data in linked list
*@head: Pointer to head node
*Return: sum of all data in list
*
*
*
*
*
*/
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *first = head;

	while (first != NULL)
	{
		sum = sum + first->n;
		first = first->next;
	}
	return (sum);
}
