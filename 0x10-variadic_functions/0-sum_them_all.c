#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all its parameters.
 * @n: argument
 * Return:0
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int x;
	int sum = 0;
	va_list num;

	if (n == 0)
		return (0);

	va_start(num, n);

	for (x = 0; x < n; x++)
	{
		sum += va_arg(num, int);
	}
	va_end(num);
	return (sum);
}
