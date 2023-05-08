#include "main.h"
#include <string.h>

/**
 * _strchr - function that locates a character in a string.
 * @s: string
 * @c: character to be located
 * Return: (NULL)
 */

char *_strchr(char *s, char c)
{
	int idx;

	for (idx = 0; s[idx] != '\0'; idx++)
	{
		if (s[idx] == c)
		{
			return (&s[idx]);
		}
	}
	return (NULL);
}
