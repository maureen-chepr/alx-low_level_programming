#include <stdio.h>

/**
 * main - progracm that prints its name, followed by a new line
 * @argc: unused number of arguments from command prompt
 * @argv: character array of pointers
 * Return: 0
 */

int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
