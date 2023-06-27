#include "coque.h"
/**
 * _path - A function that finds a path to an env variable
 * @var: Variable to be found
 * Return: Variabe or -1
 */
int _path(char *var)
{
	int ind1 = 0, ind2, lgth = cust_slen(var);
	char **domain = NULL;

	while (domain[ind1] != NULL)
	{
		ind2 = 0;
		while (domain[ind1][ind2] != '\0'
				&& domain[ind1][ind2] == var[ind2])
			ind2++;
		if (ind2 == lgth && domain[ind1][ind2] == '=')
			return (ind1);
		ind1++;
	}
	return (-1);
}

/**
 * const_path - A function that combines a directory path and
 * a command file name to create a full path
 * @ph_dir: A directory in the path
 * @arr: Directory path file
 * Return: NULL or ph
 */
char *const_path(char *ph_dir, char *arr)
{
	int ind1 = 0, ind2 = 0, lgth_d, arr_lgth, lgth;
	char *ph;

	if (ph_dir == NULL)
		return (NULL);
	lgth_d = cust_slen(ph_dir);
	arr_lgth = cust_slen(arr);
	lgth = lgth_d + arr_lgth + 1;
	ph = malloc(sizeof(char) * lgth);
	while (ph_dir[ind1] != '\0')
	{
		ph[ind1] = ph_dir[ind1];
		ind1++;
	}
	ph[ind1] = '/';
	while (arr[ind2] != '\0')
	{
		ph[ind1] = arr[ind2];
		ind1++;
		ind2++;
	}
	ph[ind1] = '\0';
	return (ph);
}

/**
 * cust_path - A function that find the path of a program
 * @arr: A command to execute
 * Return: NULL or program path
 */
char *cust_path(char *arr)
{
	char *dir, *var = "PATH", *create = NULL;
	char **parse = NULL;
	size_t new_lgth;
	int idx;

	idx = _path(var);
	parse = parse_path(idx, var);
	if (parse == NULL)
		return (NULL);
	dir = check_dir(parse, arr);
	if (dir == NULL)
	{
		/*              fr_dptr(parse);*/
		return (NULL);
	}
	new_lgth = cust_slen(dir) + cust_slen(arr) + 2;
	create = malloc(new_lgth);
	if (create != NULL)
	{
		cust_strcpy(create, dir);
		cust_strcat(create, "/");
		cust_strcat(create, arr);
	}
	fr_dptr(parse);
	return (create);
}

/**
 * check_dir - A function that searches for directories for a given file
 * @parse: A pointer to an array of strings
 * @arr: A command to execute
 * Return: NULL or directory with the command file
 */
char *check_dir(char **parse, char *arr)
{
	int ind = 0;
	struct stat stat_info;
	char *wdir = getcwd(NULL, 0);

	if (wdir == NULL)
		return (NULL);
	if (arr[0] == '/')
		arr++;
	while (parse[ind] != NULL)
	{
		if (chdir(parse[ind]) == -1)
		{
			perror("chdir");
			/*                      free(wdir);*/
			return (NULL);
		}
		if (stat(arr, &stat_info) == 0)
		{
			chdir(wdir);
			/*                      free(wdir);*/
			return (parse[ind]);
		}
		ind++;
	}
	free(wdir);
	return (NULL);
}

/**
 * parse_path - A function that breaks a sequence of strings
 * @idx: Path index in the env variables
 * @stg: String to separate and parse
 * Return: NULL pointer to the string
 */
char **parse_path(int idx, char *stg)
{
	char **domain = NULL, *var = domain[idx];
	char **parse = NULL;
	const char *space = ":\n";
	int lgth, parse_count = 0;

	lgth = cust_slen(stg);
	var = domain[idx] + (lgth + 1);
	parse = parse_link(var, space, parse_count);
	if (parse == NULL)
		return (NULL);
	return (parse);
}
