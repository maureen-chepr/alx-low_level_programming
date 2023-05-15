#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * argstostr -  function that concatenates all
 * the arguments of your program
 * @ac:first argument
 * @av:second argument
 * Return: a pointer to a new string, or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	int x, lgth = 0;
	char *str;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < ac; x++)
	{
		lgth = lgth + strlen(av[x]);
	}
	lgth = lgth + ac + 1;
	str = (char *)malloc(lgth * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	str[0] = '\0';
	x = 0;
	while (x < ac)
	{
		strcat(str, av[x]);
		strcat(str, "\n");
		x++;
	}
	return (str);
}

