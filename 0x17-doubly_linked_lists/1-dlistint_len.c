#include "lists.h"

/**
 * dlistint_len - function that returns the number of
 * elements in a linked list
 * @h: pointer to headnode
 * Return: the number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t index = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}
