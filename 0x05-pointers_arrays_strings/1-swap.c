#include "main.h"
/**
 * swap_int - function that swaps the values of two integers
 * @a: first integer
 * @b: second integer
 * Return: 0
 */

void swap_int(int *a, int *b)
{
	int f = *b;
	int k = *a;

	*b = k;
	*a = f;

}

