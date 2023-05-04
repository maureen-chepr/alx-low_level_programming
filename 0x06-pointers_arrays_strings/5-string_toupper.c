#include "main.h"
#include <string.h>
/**
 * *string_toupper - function that changes all lowercase
 *  letters of a string to uppercase
 *  @s1: string
 *  Return: s1
 */

char *string_toupper(char *s1)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] >= 97 && s1[i] <= 122)
		{
			s1[i] = s1[i] - 97 + 65;
		}
	}
	return (s1);
}
