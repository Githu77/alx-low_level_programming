#include "lists.h"
/**
*add_nodeint - add new node at beginning of the list
*@head: points to pointer to head node
*@n: The int for the new node(n_node)
*Return: NULL or address of new element
*
*
*
*
*
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *n_node;

	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
	{
		return (NULL);
	}

	n_node->n = n;
	n_node->next = *head;
	*head = n_node;

	return (n_node);
}
