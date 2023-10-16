#include "main.h"
#include <string.h>

/**
 * _strspn- functions gets length of a substring
 * @s: string to be checked
 * @accept: substring
 * Return: unsigned int bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int idx = 0;

	if (s == NULL || accept == NULL)
	{
		return (idx);
	}
	while (*s && strchr(accept, *s++))
	{
		idx++;
	}
	return (idx);
}
