#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: hash table you want to add or update the key/value to
 * @key: key
 * @value: value
 * Return: 1 on success otherwise, 0
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index, size;
	hash_node_t *curr_node, *temp;

	if (!key || !value || !ht)
		return (0);
	size = ht->size;
	index = key_index((const unsigned char *)key, size);

	temp = ht->array[index];
	while (temp != NULL)
	{
		if (temp && strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}
	curr_node = malloc(sizeof(hash_node_t));
	if (curr_node == NULL)
		return (0);

	curr_node->key = strdup(key);
	if (curr_node->key == NULL)
		return (0);

	curr_node->value = strdup(value);
	if (curr_node->value == NULL)
		return (0);

	curr_node->next = ht->array[index];
	ht->array[index] = curr_node;
	return (1);
}
