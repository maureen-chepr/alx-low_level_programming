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

	for (idx = 0; haystack[idx] != '\0'; idx++)
		while (haystack[idx + k] == needle[k] && needle[k] != '\0')
		{
			k++;
		}
	if (needle[k] == '\0')
	{
		return (needle);
	}
	return (NULL);
}
