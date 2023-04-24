#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (success) 
*/

int main(void)
{
	int n;
	int Y;
	char str[] = "Last digit of";

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	Y = n % 10;

	if (Y > 5)
	{
		printf("%s %d is %d and is greater than 5\n", str, n, Y);
	}
	else if (Y == 0)
		{
		printf("%s %d is %d and is 0\n", str, n, Y);
		}
	else
	{
	printf("%s %d is %d and is less than 6 and not 0\n", str, n, Y);
	}
	return (0);
}
