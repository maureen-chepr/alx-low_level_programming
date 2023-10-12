#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a list
 * @head: pointer to headnode
 * Return: sum or 0 if empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
