#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: no of bytes
 * Return: pointer to s3
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int x, y, lgth1 = strlen(s1), lgth2 = strlen(s2);
	char *s3;
	unsigned int lgth3 = lgth1 + n;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	if (n >= lgth2)
	{
		n = lgth2;
	}
	s3 = (char *)malloc(lgth3 + 1);
	if (s3 == NULL)
	{
		s3 = "";
	}
	for (x = 0; x < lgth1; x++)
	{
		s3[x] = s1[x];
	}
	for (y = 0; y < n; y++)
	{
		s3[x + y] = s2[y];
	}
	s3[x + y] = '\0';
	return (s3);
}



