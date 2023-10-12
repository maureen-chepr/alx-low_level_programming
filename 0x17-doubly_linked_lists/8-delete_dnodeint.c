#include "lists.h"

/**
 * delete_dnodeint_at_index - function that deletes the node at index
 * @head: pointer to headnode
 * @index: index of the node
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	dlistint_t *tmp2;
	unsigned int i;

	if (head == NULL)
		return (-1);
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}
	tmp = *head;
	i = 0;
	while (tmp != NULL)
	{
		if (i == index - 1)
		{
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			free(tmp2);
			return (1);
		}
		tmp = tmp->next;
		i++;
	}
	return (-1);
	return (1);
}
