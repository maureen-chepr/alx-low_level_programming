#include "coque.h"
/**
 * builtin_chk - A function that finds function to execute
 * @stg: The function
 * Return: NULL or a pointer
 */
void (*builtin_chk(char *stg))(char *)
{
	int ind = 0;

	builtin_cmd syst[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"cd", custom_cd},
		{"setenv", shell_setenv},
		{"unsetenv", shell_unsetenv},
		{NULL, NULL}
	};
	while (syst[ind].syst_f != NULL)
	{
		if (cust_strcmp(stg, syst[ind].syst_f) == 0)
			return (syst[ind].func);
		ind++;
	}
	return (NULL);
}

/**
 * _builtin - A function that finds builtin functions
 * @arr: Arguments passed to the shell
 * @input: User input
 * Return: 0 on succes, otherwise -1
 */
int _builtin(char **arr, char *input)
{
	void (*funct)(char *);

	funct = builtin_chk(arr[0]);
	if (funct == NULL)
		return (-1);
	if (cust_strcmp("exit", arr[0]) == 0)
		fr_dptr(arr);
	funct(input);
	return (0);
}

/**
 * cust_setenv - A function that checks if the env variable specified exists
 * @nom: Environment variable to be set
 * @val: Value to be assigned to the environment variable
 * @prev: A to be replaced
 * Return: NULL or a pointer
 */
int cust_setenv(char *nom, char *val, int prev)
{
	char **domain = NULL, **space, *new = NULL, **newdomain;
	size_t num = 0, lgth_nom = cust_slen(nom);
	size_t lgth_val = cust_slen(val);
	size_t lgth_first = lgth_nom + lgth_val + 2;

	for (space = domain; *space != NULL; ++space)
	{
		if (cust_strncmp(*space, nom, lgth_nom) == 0
				&& (*space)[lgth_nom] == '=')
		{
			if (prev != 0)
				return (0);
			new = malloc(lgth_first * sizeof(char));
			if (new == NULL)
				return (-1);
			cust_strcpy(new, nom);
			cust_strcat(new, "=");
			cust_strcat(new, val);
			free(*space);
			*space = new;
			return (0);
		}
	}
	while (domain[num] != NULL)
		++num;
	newdomain = malloc((num + 2) * sizeof(char *));
	if (newdomain == NULL)
	{
		free(new);
		return (-1);
	}
	memcpy(newdomain, domain, num * sizeof(char *));
	newdomain[num] = new;
	newdomain[num + 1] = NULL;
	domain = newdomain;
	return (0);
}

/**
 * cust_strncmp - A function that compares the first n chars of s1 and s2
 * and returns an integer
 * @s1: First string
 * @s2: Second string
 * @n: Number of chars
 * Return: n
 */
int cust_strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * cust_memcpy - A function that copies memory area
 * @dest: Destination string
 * @src: Old string
 * @n: Number of bytes
 * Return: 0
 */
char *cust_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
		*(dest + index) = *(src + index);
	return (dest);
}
