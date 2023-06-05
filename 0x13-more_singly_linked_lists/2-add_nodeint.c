#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the
 * beginning of a listint_t list
 * @head: pointer to the head of the list
 * @n: value to be stored at new node
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = (listint_t *) malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	if (!newnode)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}
