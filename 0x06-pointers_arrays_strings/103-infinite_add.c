#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer params
 * Return: 0
 */

void rev_string(char *n)
{
	int count1 = 0;
	int count2 = 0;
	char x;

	while (*(n + count1) != '\0')
	{
		count1++;
	}
	count1--;

	for (count2 = 0; count2 < count1; count2++, count1--)
	{
		x = *(n + count2);
		*(n + count2) = *(n + count1);
		*(n + count1) = x;
	}
}

/**
 * infinite_add - add 2 numbers together
 * @n1: text representation of 1st number to add
 * @n2: text representation of 2nd number to add
 * @r: pointer to buffer
 * @size_r: buffer size
 * Return: pointer to calling function
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, count1 = 0, count2 = 0, num = 0;
	int val1 = 0, val2 = 0, x_tot = 0;

	while (*(n1 + count1) != '\0')
		count1++;
	while (*(n2 + count2) != '\0')
		count2++;
	count1--;
	count2--;
	if (count2 >= size_r || count1 >= size_r)
		return (0);
	while (count2 >= 0 || count1 >= 0 || overflow == 1)
	{
		if (count1 < 0)
			val1 = 0;
		else
			val1 = *(n1 + count1) - 48;
		if (count2 < 0)
			val2 = 0;
		else
			val2 = *(n2 + count2) - 48;
		x_tot = val1 + val2 + overflow;
		if (x_tot >= 10)
			overflow = 1;
		else
			overflow = 0;
		if (num >= (size_r - 1))
			return (0);
		*(r + num) = (x_tot % 10) + 48;
		num++;
		count2--;
		count1--;
	}
	if (num == size_r)
		return (0);
	*(r + num) = '\0';
	rev_string(r);
	return (r);
}

