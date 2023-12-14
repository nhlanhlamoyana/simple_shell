#include "shell.h"
/**
 * check_for_builtins - Command to be checked if it is a builtin
 * @vars: Variables
 * Return: NULL or pointer to the function
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned int j;

	builtins_t check[] = {
		{"env", _env},
		{"exit", new_exit},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}
	};


	for (j = 0; check[j].f != NULL; j++)
	{
		if (_strcmpr(vars->av[0], check[j].name) == 0)
			break;
	}
	if (check[j].f != NULL)
		check[j].f(vars);
	return (check[j].f);
}


/**
 * new_exit - The exit program
 * @vars: Variables
 * Return: void
 */
void new_exit(vars_t *vars)
{
	int status;


	if (_strcmpr(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		status = _atoi(vars->av[1]);
		if (status == -1)
		{
			vars->status = 2;
			_puts2(vars->av[1]);
			_puts2("\n");
			print_error(vars, ": Illegal number: ");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}
	free(vars->av);
	free(vars->commands);
	free(vars->buffer);
	free_env(vars->env);
	exit(vars->status);
}

/**
 * _env - Current environment to be printed
 * @vars: Struct of variables
 * Return: void
 */
void _env(vars_t *vars)
{
	unsigned int j;

	for (j = 0; vars->env[j]; j++)
	{
		_puts(vars->env[j]);
		_puts("\n");
	}
	vars->status = 0;
}

/**
 * new_setenv - Existing variable to be edited or  new env variable is created
 * @vars: The pointer to struct of variables
 * Return: void
 */
void new_setenv(vars_t *vars)
{
	char *var;

	char **key;

	if (vars->av[1] == NULL || vars->av[2] == NULL)
	{
		vars->status = 2;

		print_error(vars, ": Incorrect number of arguments\n");

		return;
	}
	key = find_key(vars->env, vars->av[1]);
	if (key == NULL)
		add_key(vars);
	else
	{
		var = add_value(vars->av[1], vars->av[2]);
		if (var == NULL)
		{
			print_error(vars, NULL);
			free(vars->commands);
			free(vars->av);
			free(vars->buffer);
			free_env(vars->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}



/**
 * new_unsetenv - Environment variable to be removed
 * @vars: The pointer to a struct of variables
 * Return: void
 */
void new_unsetenv(vars_t *vars)
{
	char **newenv, **key;


	unsigned int j, k;


	if (vars->av[1] == NULL)
	{
		vars->status = 2;
		print_error(vars, ": Incorrect number of arguments\n");

		return;
	}
	key = find_key(vars->env, vars->av[1]);
	if (key == NULL)
	{
		print_error(vars, ": No variable to unset");
		return;
	}
	for (j = 0; vars->env[j] != NULL; j++)
		;
	newenv = malloc(sizeof(char *) * j);
	if (newenv == NULL)
	{
		vars->status = 127;
		print_error(vars, NULL);
		new_exit(vars);
	}
	for (j = 0; vars->env[j] != *key; j++)
		newenv[j] = vars->env[j];
	for (k = j + 1; vars->env[k] != NULL; k++, j++)
		newenv[j] = vars->env[k];
	newenv[j] = NULL;
	free(vars->env);
	free(*key);
	vars->status = 0;
	vars->env = newenv;
}	
