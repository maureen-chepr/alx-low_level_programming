#include "lists.h"

/**
 * free_listint2 - function that frees a listint_t list.
 * @head: pointer to the pointer to the head of the list
 */

void free_listint2(listint_t **head)
{
	listint_t *current;

	current = *head;

	if (head == NULL)
		return;
	for (; current != NULL; current = *head)
	{
		*head = (*head)->next;
		free(current);
	}
	*head = NULL;
}
