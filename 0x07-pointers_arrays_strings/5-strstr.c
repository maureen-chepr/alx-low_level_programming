#include "main.h"
#include <string.h>

/**
 * _strstr - function that locates a substring.
 * @haystack: string
 * @needle: substring
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	int idx = 0, k = 0;

	for (; haystack[idx] != '\0'; haystack++)
	{
		while (haystack[idx] == needle[k] && needle[k] != '\0')
		{
			idx++;
			k++;
		}
		if (needle[k] == '\0')
		{
			return (haystack);
		}
	}
	return (NULL);
}
