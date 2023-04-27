#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 **@n: number of times the character \ should be printed
 * Return: 0
 */

void print_diagonal(int n)
{
	int a, i;
	a = 0;

	while (n > 0)
	{
		i = a;
		while (i > 0)
		{
			_putchar(' ');
			i--;
		}
		_putchar('\\');
		_putchar('\n');
		a++;
		n--;
	}
	if (a < 1)
	{
		_putchar('\n');
	}
}
