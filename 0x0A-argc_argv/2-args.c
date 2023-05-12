#include <stdio.h>

/**
 * main - program that prints all arguments it receives.
 * @argc: arguments passed to main function from command prompt
 * @argv: character array of pointers
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int x;

	for (x = 0; x < argc; x++)
	{
		printf("%s\n", argv[x]);
	}
	return (0);
}
