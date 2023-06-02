#include "lists.h"
#include <stdlib.h>

/**
 * free_list - function that frees a list_t list
 * @head: pointer to the head of the list
 */

void free_list(list_t *head)
{
	list_t *ptr;

	for (ptr = head; ptr != NULL; ptr = head)
	{
		head = head->next;
		free(ptr->str);
		free(ptr);
	}
}
