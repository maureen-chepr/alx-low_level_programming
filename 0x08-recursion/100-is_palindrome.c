#include "main.h"

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to be reversed
 *
 * Return: 1 if it is, 0 if it's not
 */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (actual_pal(s, 0, _strlen_recursion(s)));
}

/**
 * _strlen_recursion - returns length of a string
 * @s: string length to be calculated
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * actual_pal - checks the characters recursively for palindrome
 * @s: string to check
 * @i: iterator
 * @lgth: length of the string
 * Return: 1 if palindrome, 0 if not
 */
int actual_pal(char *s, int i, int lgth)
{
	if (*(s + i) != *(s + lgth - 1))
		return (0);
	if (i >= lgth)
		return (1);
	return (actual_pal(s, i + 1, lgth - 1));
}

