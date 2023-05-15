#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - function that returns a pointer to a newly
 *  allocated space in memory, which contains a
 *  copy of the string given as a parameter.
 *  @str: string to be duplicated
 *  Return: NULL if insufficient memory was available otherwise,
 *  returns a pointer to the duplicated string
 */

char *_strdup(char *str)
{
	char *str1;
	unsigned int size;
	unsigned int x;

	if (str == NULL)
	{
		return (NULL);
	}
	size = strlen(str) + 1;
	str1 = (char *) malloc(size * sizeof(char));
	if (str1 == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		str1[x] = str[x];
	}
	return (str1);
}
