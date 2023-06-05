#include "lists.h"

/**
 * listint_len - function that returns the number of
 * elements in a linked listint_t list
 * @h: pointer to the head
 * Return: the number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *temp = h;

	for (; temp != NULL; temp = temp->next)
	{
		count++;
	}
	return (count);
}
