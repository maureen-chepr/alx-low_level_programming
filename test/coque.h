#ifndef COQUE_H
#define COQUE_H

#include <sys/wait.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#define PROMPT "$ "
#define MAX_PATH_LENGTH 1024

/**
 * struct more_builtin - Structure defined for bulitin functions
 * @syst_f: Built in command
 * @func: Pointer to the specific builtin function
 */
typedef struct more_builtin
{
	char *syst_f;
	void (*func)(char *);
} builtin_cmd;

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void custom_cd(char *input);
void _free(int result, ...);
void fr_dptr(char **tofree);
void shell_exit(char *input);
void shell_env(char *input);
void shell_setenv(char *input);
void shell_unsetenv(char *input);
char *cust_strdup(char *stg);
int write_char(char ch);
void _prints(char *stg);
void stg_print(char *stg, int sep);
int cust_slen(char *stg);
int cust_strcmp(char *s1, char *s2);
void print_nb(int nb);
void _prints_err(char *ip, int result, char *comd);
void program_err(char *ip, int result, char *old_comd);
int _builtin(char **arr, char *input);
void (*builtin_chk(char *stg))(char *);
int _path(char *var);
char *cust_path(char *arr);
char *check_dir(char **parse, char *arr);
char **parse_path(int idx, char *stg);
char *const_path(char *ph_dir, char *arr);
char *cust_strcat(char *dest, char *src);
char *cust_strcpy(char *dest, char *src);
char **_parse(int parse_result, char *input, const char *sep);
int token_qty(char *input, const char *sep);
char **parse_link(char *input, const char *sep, int parse_result);
void check_input(char *input, size_t length, int arr_res, char **ip);
void spawn_process(char **parse_arr, char *input, int result, char **ip);
char *cust_memcpy(char *dest, char *src, unsigned int n);
int cust_strncmp(char *s1, char *s2, size_t n);
int cust_setenv(char *nom, char *val, int prev);
int cust_unsetenv(char *nom);
int cust_atoi(char *stg);
void handleSIGINT(int sms);
void rmvcomment(char *insert);

#endif
