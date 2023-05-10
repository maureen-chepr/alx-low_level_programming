#include "main.h"

/**
 * is_prime_number - function that returns 1 if the input
 * integer is a prime number, otherwise return 0
 * @n: integer to be checked
 * @i: checks if n is prime number
 * Return: 0
 */

int is_prime_number(int n)
{

	if (n == 1)
	{
		return (1);
	}
	else if (n % n == 0)
	{
		return (1);
	}
	else
	{
		return (is_prime_number(n, n + 1));
        }
}
