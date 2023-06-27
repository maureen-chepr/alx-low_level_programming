#include "coque.h"
/**
 * custom_cd - A function that changes the working directory
 * @input: Argument passed on the command line
 */
void custom_cd(char *input)
{
	int idx, parse_count, prevpwd_idx;
	char **arr_arg, *cwd, *dir, *prev_pwd, **domain = NULL;
	const char *sep = "\n\t ";

	parse_count = 0;
	arr_arg = parse_link(input, sep, parse_count);
	if (arr_arg[0] == NULL)
		/*      _free(2, arr_arg, input);*/
		return;
	if (arr_arg[1] == NULL)
	{
		idx = _path("HOME");
		dir = (domain[idx]) + 5;
		if (idx == -1 || chdir(dir) == -1)
			/*      _free(2, arr_arg, input);*/
			return;
		/*              dir = (domain[idx]) + 5;
		 *              if (chdir(dir) == -1)
		 *              _free(2, arr_arg, input);*/
	}
	else if (cust_strcmp(arr_arg[1], "-") == 0)
	{
		prevpwd_idx = _path("PREVPWD");
		if (prevpwd_idx == -1)
			/*                      _free(2, arr_arg, input);*/
			return;
		prev_pwd = (domain[prevpwd_idx]) + 7;
		stg_print("%d\n", cust_atoi(prev_pwd));
		if (chdir(prev_pwd) == -1)
			/*                      _free(2, arr_arg, input);*/
			return;
	}
	else
	{
		if (chdir(arr_arg[1]) == -1)
			/*                      _free(2, arr_arg, input);*/
			return;
	}
	cwd = getcwd(NULL, 0);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		cust_setenv("PREVPWD", "PWD", 1);
		cust_setenv("PWD", cwd, 1);
	}
	_free(2, arr_arg, input);/*fr_dptr(arr_arg);*/
}

/**
 * shell_exit - A function that exits the shell
 * @input: A string representing the input
 */
void shell_exit(char *input)
{
	if (input != NULL)
		free(input);
	stg_print("\n", 1);
	exit(0);
}

/**
 * shell_env - A function that prints env variables in the shell
 * @input: A string representing the input
 */
void shell_env(char *input)
{
	int a = 0, b;
	char **domain = NULL;

	(void)input;
	while (domain[a] != NULL)
	{
		b = 0;
		while (domain[a][b] != '\0')
		{
			write(STDOUT_FILENO, &domain[a][b], 1);
			b++;
		}
		write(STDOUT_FILENO, "\n", 1);
		a++;
	}
}

/**
 * shell_setenv - A function that sets a new env variable
 * @input: A string representing the input
 */
void shell_setenv(char *input)
{
	char *nom, *val;

	strtok(input, " \t\n");
	nom = strtok(NULL, " \t\n");
	val = strtok(NULL, " \t\n");
	if (nom == NULL || val == NULL)
		_prints("Wrong num of inputs\n");
	if (cust_setenv(nom, val, 1) != 0)
		_prints("Can't set env variable\n");
}

/**
 * shell_unsetenv - A function that deletes env variable
 * @input: A string representing the input
 */
void shell_unsetenv(char *input)
{
	char *parse;
	int unset_result = 0;

	parse = strtok(input, " \t\n");
	parse = strtok(NULL, " \t\n");
	if (parse == NULL)
		_prints("Not enough inputs\n");
	while (parse != NULL)
	{
		unset_result++;
		cust_unsetenv(parse);
		parse = strtok(NULL, " \t\n");
	}
	if (unset_result == 0)
		_prints("There is no variables to unset\n");
}
