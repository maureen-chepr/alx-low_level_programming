#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - function that allocates memory
 * @b: unsigned integer
 * Return: pointer
 */

void *malloc_checked(unsigned int b)
{
	int *p;

	p = malloc(b);
	if (p == NULL)
	{
		exit(98);
	}
	return (p);
}
