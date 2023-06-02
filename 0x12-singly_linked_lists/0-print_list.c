#include "lists.h"
#include <stdio.h>

/**
 * print_list - function that prints all the elements of a list_t list
 * @h: pointer
 * Return:the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *temp = h;

	for (; temp != NULL; temp = temp->next)
	{
		if (temp->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", temp->len, temp->str);
		count++;
	}
	return (count);
}
