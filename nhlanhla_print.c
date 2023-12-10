#include "shell.h"
/**
 * nhlanhla_print - A note to be printed
 * @note: The note that will convey the required message
 * Return: void
 */
void nhlanhla_print(const char *note)
{
	write(STDOUT_FILENO,
			note, strlen(note));
}
