#include "main.h"

/**
 * _execute - execute the command
 * @cmd: command to execute
 * @av: the arguments table
 * @index: index of the line
 * Return: nothing
*/
int _execute(char **cmd, char **av, int index)
{
	pid_t fork_value;
	int stat = 0;
	char *abs_command = NULL;

	abs_command = _check_command_valid(cmd[0]);
	if (abs_command == NULL)
	{
		_print_error(av[0], cmd[0], index);
		free2D(cmd);
		return (127);
	}
	fork_value = fork();
	if (fork_value == 0)
	{
		if (execve(abs_command, cmd, environ) == -1)
		{
			free(abs_command), abs_command = NULL;
			free2D(cmd);
		}
	}
	else
	{
		waitpid(fork_value, &stat, 0);
		free2D(cmd);
		free(abs_command), abs_command = NULL;
	}
	return (WEXITSTATUS(stat));
}
