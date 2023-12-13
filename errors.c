#include "shell.h"

/**
 * print_error - Errror message to be printed to standard error
 * @msg: Messsage to be printed
 * @vars:  The pointer to struct of variables
 * Return: void
 */
void print_error(vars_t *vars, char *msg)
{
	char *count;

	_puts2(": ");
	_puts2(vars->argv[0]);
	count = _uitoa(vars->count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(vars->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}

/**
 * _puts2 - A string to be printed to standard error
 * @str: String to be printed
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(true);
	}
}


/**
 * _uitoa - An unsigned int to be converted to a string
 * @count: Unsigned int to be converted
 * Return: The pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}

