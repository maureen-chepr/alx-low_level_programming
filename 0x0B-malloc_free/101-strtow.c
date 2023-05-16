#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * strtow - function that splits a string into words
 * @str: string to be split into words
 * Return: pointer or NULL (fail)
 */
char **strtow(char *str)
{
	int words = 0, x, y, z;
	char **array;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
	{
		if (str[x] != ' ' && (x == 0 || str[x - 1] == ' '))
			words++;
	}
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	x = 0, y = 0;
	while (str[x] != '\0')
	{
		if (str[x] != ' ')
		{
			int lgth = 0;

			z = x;
			while (str[z] != ' ' && str[z] != '\0')
			{
				lgth++, z++;
			}
			array[y] = (char *)malloc((lgth + 1) * sizeof(char));
			if (array[y] == NULL)
			{
				while (y > 0)
					return (NULL);
			}
			for (z = 0; z < lgth; z++, x++)
				array[y][z] = str[x];
			array[y][z] = '\0';
			y++;
		}
		else
			x++;
	}
	return (array);
}
