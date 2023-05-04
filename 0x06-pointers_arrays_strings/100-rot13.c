#include "main.h"
#include <stdio.h>

/**
 * *rot13 - function that encodes a string using rot13.
 * @x: pointer to string
 *
 * Return: *x
 */

char *rot13(char *x)
{
	int y;
	int z;
	char s1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char s2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (y = 0; x[y] != '\0'; y++)
	{
		for (z = 0; z < 52; z++)
		{
			if (x[y] == s1[z])
			{
				x[y] = s2[z];
				break;
			}
		}
	}
	return (x);
}

