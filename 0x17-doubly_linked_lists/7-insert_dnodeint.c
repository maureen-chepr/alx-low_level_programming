#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inserts a
 * newnode at a given position
 * @h: pointer to headnode
 * @idx: index of the list
 * @n: new node
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i = 0;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *h;
		new->prev = NULL;
		if (*h)
			(*h)->prev = new;
		*h = new;
		return (new);
	}
	while (i < idx - 1)
	{
		if (temp == NULL)
		{
			free(new);
			return (NULL);
		}
		temp = temp->next;
		i++;
	}
	new->next = temp->next;
	new->prev = temp;

	if (temp->next != NULL)
		temp->next->prev = new;
	temp->next = new;
	return (new);
}
