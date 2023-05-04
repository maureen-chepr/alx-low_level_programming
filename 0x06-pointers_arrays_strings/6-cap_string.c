#include "main.h"
#include <string.h>
/**
 * *cap_string - function that capitalizes all words of a string
 * @s1: The string to be capitalized.
 *
 * Return: A pointer to the changed string.
 */
char *cap_string(char *s1)
{
	int index = 0;

	while (s1[index])
	{
		while (!(s1[index] >= 'a' && s1[index] <= 'z'))
			index++;

		if (s1[index - 1] == ' ' ||
		    s1[index - 1] == '\t' ||
		    s1[index - 1] == '\n' ||
		    s1[index - 1] == ',' ||
		    s1[index - 1] == ';' ||
		    s1[index - 1] == '.' ||
		    s1[index - 1] == '!' ||
		    s1[index - 1] == '?' ||
		    s1[index - 1] == '"' ||
		    s1[index - 1] == '(' ||
		    s1[index - 1] == ')' ||
		    s1[index - 1] == '{' ||
		    s1[index - 1] == '}' ||
		    index == 0)
			s1[index] -= 32;

		index++;
	}

	return (s1);
}

