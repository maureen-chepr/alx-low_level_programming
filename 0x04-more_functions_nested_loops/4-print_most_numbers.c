#include "main.h"

/**
 * print_most_numbers - prints the numbers, from 0 to 9
 * , followed by a new line
 */

void print_most_numbers(void)
{
	int c = 48;

	for (c = 48; c <= 57; c++)
	{
		if ((c != 50) && (c != 52))
		{
			_putchar (c);
		}
	}
	_putchar ('\n');
}
