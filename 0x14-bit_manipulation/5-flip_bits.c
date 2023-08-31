#include "main.h"

/**
 * flip_bits - function that returns the number of bits you
 * would need to flip to get from one number to another
 * @n : first number
 * @m : second number
 * Return: number of bits you need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x;
	int z = 0;

	x = n ^ m;
	while (x >= 1)
	{
		if ((x & 1) == 1)
		z++;
		x >>= 1;
	}
	return (z);
}
