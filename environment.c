#include "shell.h"
/**
 * make_env - Shell environment to be created from environment passed to main
 * @env: The environment passed to main
 * Return: Pointer to the environment that is up to date
 */
char **make_env(char **env)
{
	char **newenv = NULL;
	size_t j;

	for (j = 0; env[j] != NULL; j++)
		;
	newenv = malloc(sizeof(char *) * (j + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (j = 0; env[j] != NULL; j++)
		newenv[j] = strdup(env[j]);
	newenv[j] = NULL;
	return (newenv);
}

/**
 * free_env - The shell's environment to be freed
 * @env: The shell's environment
 * Return: void
 */
void free_env(char **env)
{
	unsigned int j;

	for (j = 0; env[j] != NULL; j++)
		free(env[j]);
	free(env);
}
