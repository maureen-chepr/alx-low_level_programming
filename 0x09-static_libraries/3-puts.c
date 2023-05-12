#include "main.h"
/**
 * _puts - function that prints a string,
 * followed by a new line, to stdout
 * @str: string to be printed
 * Return: 0
 */

void _puts(char *str)
{
	int t = 0;

	while (t >= 0)
	{
		if (str[t] == '\0')
		{
			_putchar('\n');
			break;
		}
		_putchar(str[t]);
		t++;
	}
}
