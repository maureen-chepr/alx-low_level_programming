#include "main.h"
#include <string.h>
/**
 *reverse_array - function that reverses the content of an array of integers.
 * @a: first string
 * @n: number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i;
	int x;

	for (i = 0; i <= n--; i++)
	{
		x = a[i];
		a[i] = a[n];
		a[n] = x;
	}
}
