#include "coque.h"
/**
 * cust_strcpy - A function that copies a string
 * @dest: A buffer pointer
 * @src: A string pointed
 * Return: dest
 */
char *cust_strcpy(char *dest, char *src)
{
	int ch = 0, index = 0;

	while (*(src + ch) != '\0')
		ch++;
	for ( ; index < ch ; index++)
		dest[index] = src[index];
	dest[ch] = '\0';
	return (dest);
}

/**
 * cust_strcat - A function that concatenates two strings
 * @dest: First string
 * @src: Second string
 * Return: 0
 */
char *cust_strcat(char *dest, char *src)
{
	int index, slgth1, slgth2;

	slgth1 = cust_slen(dest);
	slgth2 = cust_slen(src);
	for (index = 0; index <= slgth2; index++)
		dest[slgth1 + index] = src[index];
	return (dest);
}

/**
 * cust_strdup - A function that returns a pointer to a newly
 * allocated space in memory
 * @stg: String to be duplicated
 * Return: NULL if insufficient memory was available otherwise,
 * returns a pointer to the duplicated string
 */
char *cust_strdup(char *stg)
{
	char *stg1;
	unsigned int size, x;

	if (stg == NULL)
		return (NULL);
	size = cust_slen(stg) + 1;
	stg1 = (char *)malloc(size * sizeof(char));
	if (stg1 == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
		stg1[x] = stg[x];
	return (stg1);
}

/**
 * cust_strcmp - A function that compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if success, otherwise -1
 */
int cust_strcmp(char *s1, char *s2)
{
	int ret_val = 0;

	if (cust_slen(s1) != cust_slen(s2))
		return (-1);
	if (ret_val == 0)
		return (0);
	else
		return (ret_val);
}

/**
 * cust_slen - A function that returns the string length
 * @stg: String to be checked
 * Return: String length
 */
int cust_slen(char *stg)
{
	int lgth;

	if (stg == NULL)
		return (0);
	lgth = 0;
	while (stg[lgth] != '\0' && stg[lgth] != '\n')
		lgth++;
	return (lgth);
}
