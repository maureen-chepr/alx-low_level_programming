#include "lists.h"

/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: pointer to the pointer to the head of the list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *ptr;

	if (head == NULL)
	{
		exit(98);
	}
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		printf("[%p] %d\n", (void *)ptr, ptr->n);
		count++;
		if (ptr <= ptr->next)
		{
			printf("-> [%p] %d\n", (void *)ptr, ptr->next->n);
			exit(98);
		}
	}
	return (count);
}
