#include "main.h"

/*
 * binary_to_uint -  function that converts a binary number to an unsigned int
 * @b:  points to a string of 0 and 1 chars
 * Return: the converted number, or 0
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
