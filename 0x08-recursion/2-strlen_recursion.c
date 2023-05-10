#include "main.h"

/**
 * _strlen_recursion - function that returns the length of a string
 * @s: string to be checked
 * Return: string length
 */

int _strlen_recursion(char *s)
{
	int lgth = 0;

	if (*s == '\0')
	{
		return (lgth);
	}
	else
	{
		lgth = 1 + _strlen_recursion(s + 1);
		return (lgth);
	}
}
