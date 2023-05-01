#include "lists.h"
/**
*delete_nodeint_at_index - deletes node at specified index
*@head: pointer to head of list
*@index: index of node to delete
*Return: 1(success) or -1(unsuccessful)
*
*
*
*
*
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *prev_node, *f_node;

	if (*head == NULL)
	{
		return (-1);
	}

	f_node = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(f_node);
		return (1);
	}

	while (i < index)
	{
		prev_node = f_node;
		f_node = f_node->next;

		if (f_node == NULL)
		{
			return (-1);
		}
		i++;
	}
	prev_node->next = f_node->next;
	free(f_node);

	return (1);
}
