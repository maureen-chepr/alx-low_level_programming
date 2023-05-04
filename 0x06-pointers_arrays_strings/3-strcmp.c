#include "main.h"
#include <string.h>
/**
 * _strcmp - function that compares two strings
 * @*s1: first string
 * @*s2: second string
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int value;

	value = strcmp(s1, s2);
	if (value == 0)
	{
		return (0);
	}
	else
	{
		return (value);
        }
}
