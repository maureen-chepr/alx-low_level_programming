#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - program that adds positive numbers.
 * @argc: argument passed to main function from command prompt
 * @argv: character array of pointers
 * Return: 0 If no number is passed to the program
 * otherwise 1 If one of the number contains symbols that are not digits
 */

int main(int argc, char *argv[])
{
	int x, y, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (x = 1; x < argc; x++)
	{
		char *arg = argv[x];
		int is_valid = 1;

		for (y = 0; arg[y] != '\0'; y++)
		{
			if (!isdigit(arg[y]))
			{
				is_valid = 0;
				break;
			}
		}
		if (is_valid)
		{
			sum += atoi(arg);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);
	return (0);
}
