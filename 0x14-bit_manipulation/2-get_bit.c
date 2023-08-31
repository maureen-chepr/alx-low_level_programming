#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @n: unsigned int
 * @index:index of the bit you want to get
 * Return: bit at given index else -1 if error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (sizeof(n) * 8 < index)
		return (-1);
	n >>= index;
	if ((n & 1) == 1)
		return (1);
	else
		return (0);
}
