#include "lists.h"

/**
 * free_listint2 - function that frees a listint_t list.
 * @head: pointer to the pointer to the head of the list
 */

void free_listint2(listint_t **head)
{
	listint_t *current;
	
	if (head == NULL)
		return;
	for (current = *head; current != NULL;)
	{
		listint_t *next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
