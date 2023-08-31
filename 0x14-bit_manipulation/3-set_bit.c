#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index
 * @n: pointer to the unsigned int
 * @index: index of the bit to set
 * Return: 1 if successful, -1 if error occurrs
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if ((!n) || index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n |= (1ul << index);
	return (1);
}
