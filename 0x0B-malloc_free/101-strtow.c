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
	int flag = 0, x, y = 0;

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
	char **array;
	int words, idx;
	int len, start, word_len, i, j;

	if (str == NULL || *str == '\0')
		return (NULL);
	words = word_count(str);
	if (words == 0)
		return (NULL);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	len = strlen(str);
	idx = 0;
	start = 0;
	word_len = 0;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (word_len > 0)
			{
				array[idx] = malloc((word_len + 1) * sizeof(char));
				if (array[idx] == NULL)
				{
					for (j = 0; j < idx; j++)
						free(array[j]);
					free(array);
					return (NULL);
				}
				strncpy(array[idx], &str[start], word_len);
				array[idx][word_len] = '\0';
				idx++;
				word_len = 0;
			}
		}
		else
		{
			if (word_len == 0)
			{
				start = i;
			}
			word_len++;
		}
	}
	array[idx] = NULL;
	return (array);
}
