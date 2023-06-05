#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a
 * new node at a given position.
 * @head: pointer to the head of the list
 * @idx: the index of the list where the new node should be added
 * @n:value of the new node
 * Return: address of the new node, or NULL if it fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *ptr;
	unsigned int ind;

	ptr = *head;

	if (head == NULL)
		return (NULL);
	if (idx == 0)
	{
		newnode = malloc(sizeof(listint_t));
		if (newnode == NULL)
			return (NULL);
		newnode->n = n;
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	for (ind = 0; ind < idx - 1 && ptr != NULL ; ind++)
		ptr = ptr->next;
	if (ptr == NULL)
		return (NULL);
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = ptr->next;
	ptr->next = newnode;

	return (newnode);
}
