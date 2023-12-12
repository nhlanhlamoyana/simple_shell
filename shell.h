#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variables - variables
 * @buffer: buffer of command
 * @count: count of commands entered
 * @env: environment variables
 * @argv: arguments at opening of shell
 * @av: command line arguments
 * @position: exit position
 */
typedef struct variables
{
	char **env;
	char *buffer;
	char **av;
	size_t count;
	char **commands;
	int position;
	char **argv;

} vars_t;

/**
 * struct builtins - The struct for the builtin function
 * @f: The function for corresponding builtin
 * @name: The name of the builtin command
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

char **make_env(char **env);
void free_env(char **env);

ssize_t _puts(char *str);
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);

char **tokenize(char *buffer, char *delimiter);
char *new_strtok(char *str, const char *delim);
char **_realloc(char **ptr, size_t *size);

void new_exit(vars_t *vars);
void new_setenv(vars_t *vars);
void new_unsetenv(vars_t *vars);
void (*check_for_builtins(vars_t *vars))(vars_t *vars);
void _env(vars_t *vars);

void add_key(vars_t *vars);
int _atoi(char *str);
char **find_key(char **env, char *key);
char *add_value(char *key, char *value);

int path_execute(char *command, vars_t *vars);
char *find_path(char **env);
int execute_cwd(vars_t *vars);
void check_for_path(vars_t *vars);
int check_for_dir(char *str);

void _puts2(char *str);
void print_error(vars_t *vars, char *msg);
char *_uitoa(unsigned int count);


void display_prompt(void);
void nhlanhla_print(const char *note);
void read_format(char *format, size_t size);
void execute_command(const char *command);
#endif
