#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat -function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int size, str1, str2;
	unsigned int x = 0;

	if (s1 == NULL)
	{
		return ("");
	}
	if (s2 == NULL)
	{
		return ("");
	}
	str1 = strlen(s1);
	str2 = strlen(s2);
	size = (str1 + str2) + 1;
	s3 = (char *) malloc(size * sizeof(char));
	if (s3 == NULL)
	{
		return (NULL);
	}
	for (x = 0; x <= str2; x++)
	{
		s3[x] = s1[x];
	}
	for (x = 0; x < str2; x++)
	{
		s3[str1 + x] = s2[x];
	}
	s3[str1 + str2] = '\0';
	return (s3);
}
