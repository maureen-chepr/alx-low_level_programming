#include "main.h"

/**
* clear_bit - function that sets the value of a bit to 0 at a given index
* @n: pointer to unsigned int
* @index: index of the bit to set
* Return: 1 if works else, -1 if error occurs
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1  << index);
	return (1);
}
