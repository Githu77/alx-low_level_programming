#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*add_node - adds new node at beginning
*of list
*@head: point to head of list
*@str: string to place in new node
*Return: address of new element
*
*
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_n;
	size_t str_len = 0;

	while (str[str_len])
	{
		str_len++;
	}

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

	new_n->len = str_len;
	new_n->next = *head;
	*head = new_n;
	return (new_n);
}
