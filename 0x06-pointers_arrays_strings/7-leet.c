#include "main.h"
#include <string.h>
/**
 * *leet - function that encodes a string into 1337
 * * @x: input value
 * Return: n value
 */
char *leet(char *x)
{
	int a, b;
	char strg1[] = "aAeEoOtTlL";
	char strg2[] = "4433007711";

	for (a = 0; x[a] != '\0'; a++)
	{
		for (b = 0; b < 10; b++)
		{
			if (x[a] == strg1[b])
			{
				x[a] = strg2[b];
			}
		}
	}
	return (x);
}
