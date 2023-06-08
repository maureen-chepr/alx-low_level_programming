#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index
 * @index: the index, starting from 0 of the bit you want to set
 * @n: binary number
 * Return: 1 on success, otherwise -1 if it fails
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n ^= 1 << index;
	return (1);
}
