#include "lists.h"
/**
*add_node_end - adds new nodeat end of list
*@head: points to head node
*@str: string to add to new node
*Return: NULL or new element address
*
*
*
*
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_n, *last_n;
	unsigned int len = 0;

	new_n = malloc(sizeof(list_t));
	if (new_n == NULL)
	{
		return (NULL);
	}
	new_n->str = strdup(str);
	if (new_n->str == NULL)
	{
		free(new_n);
		return (NULL);
	}
	while (str[len])
	{
		len++;
	}
	new_n->len = len;
	new_n->next = NULL;
	if (*head == NULL)
	{
		*head = new_n;
		return (new_n);
	}
	last_n = *head;
	while (last_n->next)
	{
		last_n = last_n->next;
	}
	last_n->next = new_n;
	return (new_n);
}
