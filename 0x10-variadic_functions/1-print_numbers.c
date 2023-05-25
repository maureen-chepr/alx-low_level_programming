#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
/**
 * print_numbers - function that prints numbers, followed by a new line
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int x;
	int no;
	va_list num;

	va_start(num, n);

	for (x = 0; x < n; x++)
	{
		no = va_arg(num, int);
		printf("%d", no);
		if (separator != NULL && x < n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(num);
	printf("\n");
}
