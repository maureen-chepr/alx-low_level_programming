#include "main.h"
#include <stdlib.h>

/**
 * create_array - function that creates an array of chars,
 * and initializes it with a specific char
 * @size: no of elements
 * @c:string of characters
 * Return: NULL if size is 0,otherwise a pointer
 * to the array, or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	unsigned int x;
	char *array;

	if (size == 0)
	{
		return (NULL);
	}
	array = (char *)malloc(size * sizeof(char));

	if (array == NULL)
	{
		return (NULL);
	}
	for (x = 0; x <= size; x++)
	{
		array[x] = c;
	}
	return (array);
}

