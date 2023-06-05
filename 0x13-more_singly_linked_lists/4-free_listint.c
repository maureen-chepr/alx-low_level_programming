#include "lists.h"

/**
 * free_list - function that frees a listint_t list
 * @head: pointer to the head of the list
 */

void free_listint(listint_t *head)
{
	listint_t *ptr;

	for (ptr = head; ptr != NULL; ptr = head)
	{
		head = head->next;
		free(ptr);
	}
}
