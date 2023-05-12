#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that multiplies two numbers
 * @argc: argument passed to main function from command prompt
 * @argv: character array of pointers
 * Return: 0 if successful otherwise return 1 if there are no 2 arguments
 */

int main(int argc, char *argv[])
{
	int x, y, val;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	val = x * y;

	printf("%d\n", val);
	return (0);
}

