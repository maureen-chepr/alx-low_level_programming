#include "main.h"
#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory block using malloc and free
 * @ptr:
 * @old_size:
 * @new_size:
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
{
	if (new_size == old_size)
	{
		return (ptr);
		free(ptr);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	if (
