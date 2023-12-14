#include "shell.h"

/**
 * add_key - New environment to be created
 * @vars: The pointer to a struct of variabls
 * Return: void
 */
void add_key(vars_t *vars)
{
	char **newenv;
	unsigned int j;

	for (j = 0; vars->env[j] != NULL; j++)
		;
	newenv = malloc(sizeof(char *) * (j + 2));
	if (newenv == NULL)
	{
		vars->status = 127;
		print_error(vars, NULL);
		new_exit(vars);
	}
	for (j = 0; vars->env[j] != NULL; j++)
		newenv[j] = vars->env[j];
	newenv[j] = add_value(vars->av[1], vars->av[2]);
	if (newenv[j] == NULL)
	{
		print_error(vars, NULL);
		free(vars->commands);
		free(vars->av);
		free(newenv);
		free(vars->buffer);
		free_env(vars->env);
		exit(127);
	}
	newenv[j + 1] = NULL;
	free(vars->env);
	vars->env = newenv;
}

/**
 * find_key - Finds an environment variable
 * @key: Environment variable to be found
 * @env: Array of environment variables
 * Return: The pointer to address of the environment variable
 */
char **find_key(char **env, char *key)
{
	unsigned int j, k, len;

	len = _strlen(key);
	for (j = 0; env[j] != NULL; j++)
	{
		for (k = 0; k < len; k++)
			if (key[k] != env[j][k])
				break;
		if (k == len && env[j][k] == '=')
			return (&env[j]);
	}
	return (NULL);
}

/**
 * add_value - Anw environment variable string to be created
 * @value: Value of variable
 * @key: Name of the variable
 * Return: The pointer to the new string
 */
char *add_value(char *key, char *value)
{
	char *new;
	unsigned int len1, len2, j, k;

	len1 = _strlen(key);
	len2 = _strlen(value);
	new = malloc(sizeof(char) * (len1 + len2 + 2));
	if (new == NULL)
		return (NULL);
	for (j = 0; key[j] != '\0'; j++)
		new[j] = key[j];
	new[j] = key[j];
	new[j] = '=';
	for (k = 0; value[k] != '\0'; k++)
		new[j + 1 + k] = value[k];
	new[j + 1 + k] = '\0';
	return (new);
}

/**
 * _atoi - A string to be converted into an integer
 * @str: String to be converted
 * Return: -1 if an error arises or the value of the integer
 */
int _atoi(char *str)
{
	int num = 0, num_test;
	unsigned int j, digits;

	num_test = INT_MAX;
	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;
	for (j = 0; str[j] != '\0' && j < digits; j++)
	{
		num *= 10;
		if (str[j] < '0' || str[j] > '9')
			return (-1);
		if ((j == digits - 1) && (str[j] - '0' > INT_MAX % 10))
			return (-1);
		num += str[j] - '0';
		if ((j == digits - 2) && (str[j + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (j > digits)
		return (-1);
	return (num);
}
