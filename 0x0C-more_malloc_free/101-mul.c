#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * multiply - multiplies two positive integers
 * @num1: first number
 * @num2: second number
 * Return: the product of num1 and num2
 */
int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * isPositiveNumber - checks if a string represents a positive number
 * @s: string to be evaluated
 * Return: 1 if s is a positive number, 0 otherwise
 */
int isPositiveNumber(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3 || !isPositiveNumber(argv[1]) || !isPositiveNumber(argv[2]))
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = multiply(num1, num2);

	printf("%d\n", result);

	return (0);
}

