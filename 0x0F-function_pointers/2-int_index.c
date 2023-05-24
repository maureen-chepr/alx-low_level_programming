#include "function_pointers.h"

/**
 * int_index - function that searches for an integer.
 * @size:the number of elements in the array
 * @cmp:pointer to the function to be used to compare values
 * Return:index otherwise, -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int idx;

	if (size <= 0)
	{
		return (-1);
	}
	for (idx = 0; idx < size; idx++)
	{
		if (cmp(array[idx]) != 0)
		{
			return (idx);
		}
	}
	return (-1);
}
