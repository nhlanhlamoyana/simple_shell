#include "shell.h"
/**
 * main - Main
 * Return: 0 if successful
 */
int main(void)
{
	char command[120];

	while (1)
	{
		display_prompt();
		read_format(command, 
				sizeof(command));

		execute_command(command);
		return (0);
	}
}
