#include "main.h"
/**
 * puts_half - function that prints a string,
 * followed by a new line, to stdout
 * @str: string to be printed
 * Return: 0
 */

void puts_half(char *str)
{
	int x = 0, y, length = 0;

	while (str[x] != '\0')
	{
		x++;
		length++;
	}
	y = length / 2;
	if ((length % 2) == 1)
	{
		y = ((length + 1) / 2);
	}
	for (x = y; str[x] != '\0'; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');
}
