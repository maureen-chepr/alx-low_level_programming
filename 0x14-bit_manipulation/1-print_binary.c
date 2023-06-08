#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @n: binary result to be printed
 */

void print_binary(unsigned long int n)
{
	 int ind = 63;
	 int bits = 0;
	 unsigned long int currbit;
	 
	 while (ind >= 0)
	 {
		 currbit = n >> ind;
		 if (currbit & 1)
		 {
			 _putchar('1');
			 bits++;
		 }
		 else if (bits)
		 {
			 _putchar('0');
		 }
		 ind--;
	 }
	 if (!bits)
	 {
		 _putchar('0');
	 }
}
