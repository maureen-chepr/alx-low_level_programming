#include "main.h"
#include <stdlib.h>

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: no of elements
 * @size: no of bytes
 * Return: a pointer or 0 if it fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int x;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = (char *)malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < nmemb * size; x++)
	{
		p[x] = 0;
	}
	return (p);
}

