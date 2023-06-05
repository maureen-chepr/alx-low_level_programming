#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node
 * at the end of a listint_t list
 * @head: double pointer to the listint_t list
 * @n: value to be stored in the new node
 * Return: address of the new element, or NULL if it fails
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *temp;

	temp = *head;

	newnode = (listint_t *) malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	if (!newnode)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		for (; temp->next != NULL; temp = temp->next)
		{
			;
		}
		temp->next = newnode;
	}
	return (newnode);
}
