#include "main.h"

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: integer to be checked
 * Return: 0
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (real_sqrt_recursion(n, 1));
	}
}

/**
 * real_sqrt_recursion - function that recurses to find the natural
 * square root of a number
 * @n: integer to the check the square root
 * @i: iterator
 * Return: square root
 */

int real_sqrt_recursion(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	else if (i * i == n)
	{
		return (i);
	}
	else
	{
		return (real_sqrt_recursion(n, i + 1));
	}
}
