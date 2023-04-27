#include "main.h"

/**
 * more_numbers  - prints 10 times the numbers, from 0 to 14
 * , followed by a new line
 */

void more_numbers(void)
{
	int a;
	int i;

	i = 0;
	
	while (i < 10)
	{
		a = 48;
		while (a <= 14)
		{
			_putchar(a);
			a++;
		}
		_putchar ('\n');
		i++;
		}
}
