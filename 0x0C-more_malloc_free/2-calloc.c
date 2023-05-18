#include "main.h"
#include <stdlib.h>

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb:
 * @size:
 * Return: a pointer or 0 if it fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = (int*)malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}

