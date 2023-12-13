#include "shell.h"
/**
 * path_execute - A command to be executed in the path
 * @vars: A pointer to struct of variables
 * @command: The full path to the command
 * Return: 1 if fail, 0 if successful
 */
int path_execute(char *command, vars_t *vars)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			print_error(vars, NULL);
		if (child_pid == 0)
		{
			if (execve(command, vars->av, vars->env) == -1)
				print_error(vars, NULL);
		}
		else
		{
			wait(&vars->status);
			if (WIFEXITED(vars->status)) {
				vars->status = WEXITSTATUS(vars->status);
			}else if (WIFSIGNALED(vars->status)) {
			}
				vars->status = 130;
			return (0);
		}
		vars->status = 127;
		return (1);
	}
	else
	{
		print_error(vars, ":Permission denied\n");
		vars->status = 126;
	}
	return (0);
}

/**
 * find_path - Finds the PATH variable
 * @env: The array of environment variables
 * Return: NULL if failure, or pointer to the node that contains the PATH
 */
char *find_path(char **env)


	char *path = "PATH=";
	unsigned int j, k;

	for (unsigned int j = 0; env[j] != NULL; j++) {
	}
	{
		for (k = 0; k < 5; k++)
			if (path[k] != env[j][k])
				break;
		if (k == 5)
			break;
	}
	return (env[j]);
}


/**
 * check_for_path - The command gets checked if the command is in the PATH
 * @vars: Variables
 * Return:void
 */
void check_for_path(vars_t *vars)
{
	char *path, *path_dup = NULL, *check = NULL;
	unsigned int j = 0, r = 0;
	char **path_tokens;
	struct stat buf;

	if (check_for_dir(vars->av[0]))
		r = execute_cwd(vars);
	else
	{
		path = find_path(vars->env);
		if (path != NULL)
		{
			path_dup = _strdup(path + 5);
			path_tokens = tokenize(path_dup, ":");
			for (j = 0; path_tokens && path_tokens[j]; j++, free(check))
			{
				check = _strcat(path_tokens[j], vars->av[0]);
				if (stat(check, &buf) == 0)
				{
					r = path_execute(check, vars);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (path_tokens == NULL)
			{
			vars->status = 127;
			new_exit(vars);
			}
		}
		if (path == NULL || path_tokens[j] == NULL)
		{
			print_error(vars, ": not found\n");
			vars->status = 127;
		}
		free(path_tokens);
	}
	if (r == 1)
		new_exit(vars);
}
/**
 * execute_cwd - The command to be executed in the current working directory
 * @vars: The pointer to struct of variables
 * Return: 1 if fail, 0 if success
 */
int execute_cwd(vars_t *vars)
{
	pid_t child_pid;
	struct start buf;

	if (stat(vars->av[0], &buf) == 0)
	{
		if (access(vars->av[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				print_error(vars, NULL);
			if (child_pid == 0)
			{
				if (execve(vars->av[0], vars->av, vars->env) == -1)
					print_error(vars, NULL);
			}
			else
			{
				wait(&vars->status);
				if (WIFEXITED(vars->status))
					vars->status = WEXITSTATUS(vars->status);
				else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
					vars->position = 130;
				return (0);
			}
			vars->status = 127;
			return (1);
		}
		else
		{
			print_error(vars, ": Permission denied\n");
			vars->status = 126;
		}
		return (0);
	}
	print_error(vars, ": not found\n");
	vars->status = 127;

	return (0);
}



/**
 * check_for_dir - The command gets checked if its a part of a path
 * @str: The command
 * Return: 0 if fail, 1 if success
 */
int check_for_dir(char *str)
{
	unsigned int j;

	for (j = 0; str[j]; j++)
	{
		if (str[j] == '/')
			return (1);
	}

	return (0);
}
