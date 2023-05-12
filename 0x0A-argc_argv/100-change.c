#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that prints the minimum number of
 * coins to make change for an amount of money.
 * @argc: argument passed to main function from command prompt
 * @argv: character array of pointers
 * Return: 1 if the number of arguments passed to your program is not exactly 1
 */

int main(int argc, char *argv[])
{
	int cents, x, change;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	cents = atoi(argv[1]);
	change = 0;
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	for (x = 0; x < 5 && cents >= 0; x++)
	{
		while (cents >= coins[x])
		{
			change++;
			cents -= coins[x];
		}
	}
	printf("%d\n", change);
	return (0);
}
