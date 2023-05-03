#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int code[100];
	int idx, sum, n;

	sum = 0;	

	srand(time(NULL));

	for (idx = 0; idx <= 99; idx++)
	{
		code[idx] = rand() % 78;
		sum += (code[idx] + 48);
		putchar(code[idx] + 48);
		if ((2772 - sum) - 48 < 78)
		{
			n = 2772 - sum - 48;
			sum += n;
			putchar(n + 48);
			break;
		}
	}

	return (0);
}

