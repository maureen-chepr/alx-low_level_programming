#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - prints the lowercase alphabet in reverse,
 * followed by a new line
 * Return: Always 0 (Success)
 */

int main(void)
{
	char za;

	for (za = 'z'; za >= 'a'; za--)
	{
		putchar(za);
	}
	putchar('\n');

	return (0);
}
