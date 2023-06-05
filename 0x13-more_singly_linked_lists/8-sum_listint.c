#include "lists.h"

/**
 * sum_listint - function that returns the sum of all
 * the data (n) of a listint_t linked list
 * @head: pointer to the head of the list
 * Return: sum of the data (n) of the linked list
 * otherwise, 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *ptr;

	ptr = head;
	for (; ptr != NULL; ptr = ptr->next)
	{
		sum = sum + ptr->n;
	}
	return (sum);
}
