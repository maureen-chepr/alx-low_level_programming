#include "hash_tables.h"

/**
 * shash_table_create - a function that creates ht
 * @size: size of the array
 * Return: 0 on success otherwise, NULL
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *srt_ht;
	unsigned long int idx;

	if (size == 0)
		return (NULL);
	srt_ht = malloc(sizeof(shash_table_t));
	if (srt_ht == NULL)
		return (NULL);
	srt_ht->size = size;
	srt_ht->array = malloc(sizeof(shash_node_t *) * size);
	if (srt_ht->array == NULL)
	{
		free(srt_ht);
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
	{
		srt_ht->array[idx] = NULL;
	}
	srt_ht->shead = srt_ht->stail = NULL;
	return (srt_ht);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 * Return: pointer to the new node, or NULL on failure
 */

shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *s_hn;

	s_hn = malloc(sizeof(shash_node_t));
	if (s_hn == NULL)
		return (NULL);
	s_hn->key = strdup(key);
	if (s_hn->key == NULL)
	{
		free(s_hn);
		return (NULL);
	}
	s_hn->value = strdup(value);
	if (s_hn->value == NULL)
	{
		free(s_hn->key);
		free(s_hn);
		return (NULL);
	}
	s_hn->next = s_hn->snext = s_hn->sprev = NULL;
	return (s_hn);
}

/**
 * add_node - add a node
 * @table: the sorted hash table
 * @node: the node to add
 * Return: void
 */
void add_node(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *tmp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	tmp = table->shead;
	while (tmp != NULL)
	{
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		tmp = tmp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *new_value;
	shash_node_t *s_hn, *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}
	s_hn = make_shash_node(key, value);
	if (s_hn == NULL)
		return (0);
	s_hn->next = ht->array[idx];
	ht->array[idx] = s_hn;
	add_node(ht, s_hn);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
