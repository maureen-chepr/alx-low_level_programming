#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int num;
	unsigned int value = 0;

	if (!b)
		return (0);
	for (num = 0; b[num]; num++)
	{
		if (b[num] < '0' || b[num] > '1')
			return (0);
		value = 2 * value + (b[num] - '0');
	}
	return (value);
}
