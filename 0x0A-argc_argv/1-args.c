#include <stdio.h>

/**
 * main - program that prints the number of arguments
 * passed into it,followed by a new line.
 * @argc: argument passed to main function from command prompt
 * @argv: unused character array of pointers
 * Return: 0
 */

int main(int argc, char **argv)
{
	(void)*argv;
	printf("%d\n", argc - 1);
	return (0);
}
