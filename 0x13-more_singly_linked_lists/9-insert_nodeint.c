#include "lists.h"
/**
*insert_nodeint_at_index - inserts new node at a point in list
*@head: points to pointer to the first node of list
*@idx: index of list where to add new node
*@n: data to store in new node
*Return: address to new node
*
*
*
*
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *n_node, *f_node;
	unsigned int i;

	if (!head)
	{
		return (NULL);
	}
	if (idx == 0)
	{
		n_node = add_nodeint(head, n);
		return (n_node);
	}
	f_node = *head;
	for (i = 0; i < idx - 1 && f_node; i++)
	{
		f_node = f_node->next;
	}
	if (i != idx - 1)
	{
		return (NULL);
	}
	n_node = malloc(sizeof(listint_t));
	if (!n_node)
	{
		return (NULL);
	}
	n_node->n = n;
	n_node->next = f_node->next;
	f_node->next = n_node;
	return (n_node);
}
