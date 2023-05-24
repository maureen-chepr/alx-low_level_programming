#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - prints each array elem
 * @array: array
 * @size: no of elem to print
 * @action: function pointer
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int idx;

	if (array == NULL || action == NULL)
		return;

	for (idx = 0; idx < size; idx++)
	{
		action(array[idx]);
	}
}

