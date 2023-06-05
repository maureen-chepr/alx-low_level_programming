#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t
 * linked list, and returns the head node’s data (n)
 * @head: pointer to the head of the list
 * Return:value of the deleted head node otherwise, 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	int x;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0);
	temp = *head;
	x = temp->n;
	*head = temp->next;

	return (x);
}
