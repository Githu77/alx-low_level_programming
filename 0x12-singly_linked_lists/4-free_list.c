#include "lists.h"
/**
*free_list - frees a list
*@head: pointer to head list
*
*
*
*
*
*/
void free_list(list_t *head)
{
	list_t *ls;

	while (head != NULL)
	{
		ls = head;
		head = head->next;
		free(ls->str);
		free(ls);
	}
}
