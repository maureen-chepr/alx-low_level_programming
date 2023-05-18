#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
/**
 * main - program that multiplies two positive numbers
 * @argc:argument passed to main
 * @argv:character array of pointers
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int num1;
	int num2;
	int mul, x, y;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (x = 1; x < argc; x++)
	{
		for (y = 0; argv[x][y] != '\0'; y++)
		{
			if (!isdigit(argv[x][y]))
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	mul = num1 * num2;

	printf("%d\n", mul);
	return (0);
}
