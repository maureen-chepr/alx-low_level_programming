#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: size of the array
 * Return: 0 on success otherwise, NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_hasht;
	unsigned long int idx;

	new_hasht = malloc(sizeof(hash_table_t));
	if (new_hasht == NULL)
		return (NULL);
	new_hasht->array = malloc(sizeof(hash_node_t *) * size);
	if (new_hasht->array == NULL)
	{
		free(new_hasht);
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
	{
		new_hasht->array[idx] = NULL;
	}
	new_hasht->size = size;
	return (new_hasht);
}
