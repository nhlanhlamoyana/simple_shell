#include "shell.h"
/**
 * execute_command - Command to be executed
 * @command: Pointer to character that will be executed
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork(); 	

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		child process excelp(command, command, (char *)NULL);
		perror("excelp");
		exit(EXIT_FAILURE);
	}
	else 
	{
		parent process
			wait (NULL);
	}
}

#include "shell.h"
/**
 * execute_command - Command to be executed.
 * @command: Pointer to character that will be executed.
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		nhlanhla_print("Error forking process .\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		child process

		char *args[128];
		int arg_count = 0;

		char *sign = strtok((char *)command, " ");

		while (sign != NULL)
		{
			args[arg_count++] = sign;
			sign = strtok(NULL, " ");
		}
		args[arg_count] = NULL;	
		execvp(args[0], args);

		nhlanhla_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else 
	{
		wait(NULL);
	}


}
