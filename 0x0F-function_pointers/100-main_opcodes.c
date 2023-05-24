#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 * Return:0
 */

int main(int argc, char *argv[])
{
	int no_bytes;
	char *array;
	int idx;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	no_bytes = atoi(argv[1]);
	if (no_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	array = (char *)&main;
	for (idx = 0; idx < no_bytes; idx++)
	{
		if (idx == no_bytes - 1)
		{
			printf("%02hhx\n", array[idx]);
			break;
		}
		printf("%02hhx ", array[idx]);
	}
	return (0);
}


