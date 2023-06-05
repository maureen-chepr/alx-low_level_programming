#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list
 * @head: pointer to the head of the list
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp = NULL, *ptr = NULL;

	if (head == NULL)
	{
		return (NULL);
	}
	for (; *head != NULL; *head = temp)
	{
		temp = (*head)->next;
		(*head)->next = ptr;
		ptr = *head;
	}
	*head = ptr;

	return (*head);
}
