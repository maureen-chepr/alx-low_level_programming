#include "main.h"
/**
 * print_rev - function that prints a string, in reverse
 * , followed by a new line
 * @s: string to be printed
 */

void print_rev(char *s)
{
	int g = 0;

	while (g >= 0)
	{
		if (s[g] == '\0')
		{
			break;
		}
		g++;
	}
	for (g -= 1; g >= 0; g--)
	{
		_putchar(s[g]);
	}
	_putchar('\n');
}
