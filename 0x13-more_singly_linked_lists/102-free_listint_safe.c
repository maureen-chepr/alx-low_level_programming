#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list
 * @h: pointer to the pointer to the head of the list
 * Return: the size of the list that was free'd
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;
	
	if (h == NULL)
		return (0);
	for (current = *h; current != NULL; current = next)
	{
		next = current->next;
		printf("[%p] %d\n", (void *)current, current->n);
		free(current);
		count++;
		if (current >= next)
		{
			printf("-> [%p] %d\n", (void *)current, next->n);
			break;
		}
	}
	*h = NULL;
	
	return (count);
}
