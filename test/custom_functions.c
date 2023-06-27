#include "coque.h"
/**
 * _prints - A function that prints a string
 * @stg: String to be printed
 * Return: 0
 */
void _prints(char *stg)
{
	int it = 0;

	while (it >= 0)
	{
		if (stg[it] == '\0')
		{
			write_char('\n');
			break;
		}
		write_char(stg[it]);
		it++;
	}
}

/**
 * stg_print - A function that takes two arguments and prints a
 * string char by char
 * @stg: String to be printed
 * @sep: Separator between characters of the string
 */
void stg_print(char *stg, int sep)
{
	int ind = 0;

	if (stg == NULL)
		stg = "(nil)";
	while (stg[ind] != '\0')
	{
		write(STDOUT_FILENO, &stg[ind], 1);
		ind++;
	}
	if (sep == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * write_char - A function that writes a character
 * @ch: The character to print
 * Return: 1 on success, -1 on error
 */
int write_char(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * spawn_process - A function that creates a new process
 * @parse_arr: Pointers to strings
 * @input: A string representing the input
 * @result: A tally of inputs
 * @ip: Number of commands run on the shell
 */
void spawn_process(char **parse_arr, char *input, int result, char **ip)
{
	pid_t process;
	char *old_comd, *arr, **domain = NULL;
	int cond, ind, find;
	struct stat buffer;

	process = fork();
	if (process == 0)
	{
		old_comd = parse_arr[0];
		arr = cust_path(parse_arr[0]);
		if (arr == NULL)
		{
			find = stat(old_comd, &buffer);
			if (find == -1)
			{
				_prints_err(ip[0], result, old_comd);
				stg_print(": not found", 0);
				_free(2, input, old_comd);
				for (ind = 1; parse_arr[ind]; ind++)
					free(parse_arr[ind]);
				free(parse_arr);
				exit(100);
			}
			free(old_comd);
			arr = old_comd;
		}
		parse_arr[0] = arr;
		if (parse_arr[0] != NULL)
		{
			if (execve(parse_arr[0], parse_arr, domain) == -1)
				program_err(ip[0], result, old_comd);
		}
	}
	else
	{
		wait(&cond);
		_free(2, input, parse_arr);
	}
}

/**
 * cust_unsetenv - A function that unsets environment variable
 * @nom: Environment variable
 * Return: 0
 */
int cust_unsetenv(char *nom)
{
	int ind1, ind2, slgth;
	char **domain = NULL;

	slgth = cust_slen(nom);
	for (ind1 = 0; domain[ind1] != NULL; ind1++)
	{
		if (cust_strncmp(nom, domain[ind1], slgth) == 0
				&& domain[ind1][slgth] == '=')
		{
			for (ind2 = ind1; domain[ind2] != NULL; ind2++)
				domain[ind2] = domain[ind2 + 1];
			return (0);
		}
	}
	return (-1);
}

