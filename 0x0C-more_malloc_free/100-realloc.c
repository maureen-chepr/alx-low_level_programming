#include "main.h"
#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory block using malloc and free
 * @ptr:pointer to the memory previously allocated
 * @old_size:size, in bytes, of the allocated space for ptr
 * @new_size:new size, in bytes of the new memory block
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		return (NULL);
		free(ptr);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	ptr = malloc(new_size);
	return (ptr);
}
