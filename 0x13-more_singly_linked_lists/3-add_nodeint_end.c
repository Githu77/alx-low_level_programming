#include "lists.h"
/**
*add_nodeint_end - adds new node at end
*@head: pointer to head nod of list
*@n: value of int to store
*Return: address of new element
*
*
*
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *n_node, *l_node;

	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
	{
		return (NULL);
	}

	n_node->n = n;
	n_node->next = NULL;

	if (*head == NULL)
	{
		*head = n_node;
		return (n_node);
	}

	l_node = *head;
	while (l_node->next != NULL)
	{
		l_node = l_node->next;
	}
	l_node->next = n_node;

	return (n_node);
}
