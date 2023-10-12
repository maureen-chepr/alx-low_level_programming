#include "lists.h"

/**
 * print_dlistint - function that prints all the elements of a list
 * @h: pointer to headnode
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t index = 0;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		index++;
	}
	return (index);
}
