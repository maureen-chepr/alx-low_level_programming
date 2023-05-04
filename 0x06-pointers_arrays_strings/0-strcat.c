#include "main.h"
#include <string.h>
/**
 * *_strcat - function that concatenates two strings.
 * @dest: first string
 * @src: second string
 * Return: 0 
 */

char *_strcat(char *dest, char *src)
{
	int i, length1, length2;

	length1 = strlen(dest);
	length2 = strlen(src);
	for (i = 0; i <= length2; i++)
	{
		dest[length1 + i] = src[i];
	}
	return (dest);
}
