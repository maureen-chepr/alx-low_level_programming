#include "main.h"
#include <string.h>
/**
 * *_strncat - function that concatenates two strings.
 * @dest: first string
 * @src: second string
 * @n: number of bytes
 * Return: 0
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, length1;

	length1 = strlen(dest);
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[length1 + i] = src[i];
	}
	dest[length1 + i] = '\0';
	return (dest);
}
