#include "main.h"
#include <stdlib.h>

/**
 * array_range - function that creates an array of integers
 * @min: min range of integers
 * @max: max range of integers
 * Return: pointer or NULL;
 */

int *array_range(int min, int max)
{
	int *array;
	int num, x;

	if (min > max)
	{
		return (NULL);
	}
	num = max - min + 1;
	array = (int *)malloc(num * sizeof(int));
	if (array == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < num; x++)
	{
		array[x] = min++;
	}
	return (array);
}
