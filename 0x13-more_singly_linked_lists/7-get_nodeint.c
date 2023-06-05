#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the
 * nth node of a listint_t linked list
 * @index: is the index of the node, starting at 0
 * @head: pointer to the head of the list
 * Return: pointer to the nth node, or NULL if the node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *ptr;

	ptr = head;

	for (; ptr != NULL; ptr = ptr->next)
	{
		if (index == 0)
			return (ptr);

		index--;
	}
	return (NULL);
}
