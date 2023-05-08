#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals
 *  of a square matrix of integers.
 *  @a: array
 *  @size: size of array
 */

void print_diagsums(int *a, int size)
{
	int sum0 = 0, sum1 = 0, i;

	for (i = 0; i < size; i++)
	{
		sum0 = (*(a + i) * (size + 1));
		sum1 = (*(a + i) * size +( size -i -1));
	}
} 
