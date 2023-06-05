#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node
 * at index index of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptr, *temp;
	
	unsigned int i;
	ptr = *head;
	temp = NULL;
	
	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = ptr->next;
		free(ptr);
		return (1);
	}
	for (i = 0; i < index && ptr != NULL; i++)
	{
		temp = ptr;
		ptr = ptr->next;
	}
	if (ptr == NULL)
		return (-1);
	temp->next = ptr->next;
	free(ptr);

	return (1);
}
