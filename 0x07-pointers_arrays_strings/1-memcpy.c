#include "main.h"

/**
 * _memcpy - function that copies memory area
 * @n: bytes from memory area
 * @src: memory area
 * @dest: destination
 * Return: (dest)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	for (idx = 0; idx < n; idx++)
	{
		*(dest + idx) = *(src + idx);
	}
	return (dest);
}
