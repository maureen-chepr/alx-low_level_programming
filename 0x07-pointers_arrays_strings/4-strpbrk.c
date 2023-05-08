#include "main.h"
#include <string.h>
/**
 * _strpbrk - function that searches a string for any of a set of bytes
 * @s: string
 * @accept: the substring bytes to be checked
 * Return: pointer to the byte in s that matches one of the bytes in accept
 * , or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int idx, k;

	for (idx = 0; s[idx] != '\0'; idx++)
	{
		for (k = 0; accept[k] != '\0'; k++)
			if (s[idx] == accept[k])
			{
				return (&s[idx]);
			}
	}
	return (NULL);
}
