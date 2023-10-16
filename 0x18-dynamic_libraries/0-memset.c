#include "main.h"

/**
 * _memset - function that fills memory with a constant byte.
 * @s: pointer to the memory area
 * @n: bytes of the memory
 * @b: value to be filled with n bytes
 * Return: (s)
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int idx;

	for (idx = 0; idx < n; idx++)
	{
		*(s + idx) = b;
	}
	return (s);
}
