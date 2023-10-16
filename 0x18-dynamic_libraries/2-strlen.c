#include "main.h"
/**
 * _strlen - function that returns the length of a string
 * @s: length of a string to be determined
 * Return: (x)
 */

int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
