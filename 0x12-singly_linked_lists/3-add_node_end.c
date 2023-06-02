#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - function that adds a new node
 * at the end of a list_t list
 * @head: double pointer to the list_t list
 * @str: the new string which is added to node
 * Return: address of the new element, or NULL if it fails
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode, *temp;

	temp = *head;

	newnode = (list_t *) malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	newnode->str = strdup(str);
	if (!newnode)
	{
		return (NULL);
	}
	newnode->len = strlen(str);
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
