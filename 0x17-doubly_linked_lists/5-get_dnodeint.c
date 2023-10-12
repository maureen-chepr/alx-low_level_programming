#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the nth node of a list
 * @head:pointer to headnode
 * @index:index of the node
 * Return: nth node else, NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	unsigned int idx = 0;

	while (temp != NULL && idx < index)
	{
		temp = temp->next;
		idx++;
	}
	return (temp);
}
