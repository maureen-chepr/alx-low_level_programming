#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int idx, x, y, length, z, num;

	idx = 0;
	x = 0;
	y = 0;
	length = 0;
	z = 0;
	num = 0;

	while (s[length] != '\0')
		length++;

	while (idx < length && z == 0)
	{
		if (s[idx] == 45)
			++x;

		if (s[idx] >= 48 && s[idx] <= 57)
		{
			num = s[idx] - 48;
			if (x % 2)
				num = -num;
			y = y * 10 + num;
			z = 1;
			if (s[idx + 1] < 48 || s[idx + 1] > 57)
				break;
			z = 0;
		}
		idx++;
	}

	if (z == 0)
		return (0);

	return (y);
}
