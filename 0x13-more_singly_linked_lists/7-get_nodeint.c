#include "lists.h"
/**
*get_nodeint_at_index - returns nth node of list
*@head: pointer to head node of the list
*@index: index of required node
*Return: NULL or pointer to nth node
*
*
*
*
*
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *first = head;

	for (i = 0; i < index && first != NULL; i++)
	{
		first = first->next;
	}
	return (first);
}
