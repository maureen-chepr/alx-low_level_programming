#include "lists.h"

/**
 * free_dlistint - function that frees a dlistint_t list
 * @head: pointer head
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;
	dlistint_t *next;

	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
