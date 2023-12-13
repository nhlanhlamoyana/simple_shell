#include "shell.h"

/**
 * tokenize - A buffer gets tokenized with a delimiter
 * @delimiter: Delimiter to tokenize along
 * @buffer: Buffer to tokenize
 * Return: A pointer to an array of pointers to the tokens
 */
char **tokenize(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t j = 0, mcount = 10;


	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[j] = new_strtok(buffer, delimiter)) != NULL)
	{
		j++;
		if (j == mcount)
		{
			tokens = _realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}	
		buffer = NULL;
	}
	return (tokens);
}

