#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * word_count- counts the number of words in a string
 * @str: string to evaluate
 *Return: no of words
 */
int word_count(char *str)
{
	int flag, x, y = 0;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (str[x] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			y++;
		}
	}
	return (y);
}

/**
 * strtow -  function that splits a string into words
 * @str: string to be split to words
 * Return: pointer to an array of strings (Success)
 * or NULL (fail)
 */
char **strtow(char *str)
{
	char **array, *s1;
	int x, y = 0, lgth = 0, words, z = 0, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	lgth = strlen(str);
	words = word_count(str);
	if (words == 0)
	{
		return (NULL);
	}
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (array == NULL)
	{
		return (NULL);
	}
	for (x = 0; x <= lgth; x++)
	{
		if (str[x] == ' ' || str[x] == '\0')
		{
			if (z)
			{
				end = x;
				s1 = (char *)malloc((z + 1) * sizeof(char));
				if (s1 == NULL)
					return (NULL);
				while (start < end)
					*s1++ = str[start++];
				*s1= '\0';
				array[y] = s1 - z;
				y++;
				z = 0;
			}
			else if (z++ == 0)
			{
				start = x;
			}
		}
	}
	array[y] = NULL;
	return (array);
}
