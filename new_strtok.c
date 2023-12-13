#include "shell.h"
/**
 * check_match - Character to be checked if  character matches any in a string
 * @str: The string to be checked
 * @c: The character to be checked
 * Return: 0 if no match, 1 if match
 */
unsigned int check_match(char c, const char *str)
{
	unsigned int j;


	for (j = 0; str[j] != '\0'; j++)
	{
		if (c == str[j])
			return (1);
	}
	return (0);
}

/**
 * new_strtok - The custom strtok
 * @delim: The delimiter to tokenize against
 * @str: The string to be tokenized
 * Return: NULL or pointer to the next token
 */
char *new_strtok(char *str, const char *delim)
{
	unsigned int j;
	static char *token_start;
	static char *next_token;


	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (j = 0; next_token[j] != '\0'; j++)
	{
		if (check_match(next_token[j], delim) == 0)
			break;
	}
	if (next_token[j] == '\0' || next_token[j] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + j;
	next_token = token_start;
	for (j = 0; next_token[j] != '\0'; j++)
	{
		if (check_match(next_token[j], delim) == 1)
			break;
	}
	if (next_token[j] == '\0')
		next_token = NULL;
	else
	{
		next_token[j] = '\0';
		next_token = next_token + j + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}
