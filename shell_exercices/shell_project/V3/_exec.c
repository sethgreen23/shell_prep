#include "main.h"
/**
 * _execute - execute command
 * @command: command array
 * @argv: arguments
 *
 * Return: status code of execution
*/
int _execute(char **command, char **argv)
{
	pid_t child_pid = 0;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			free2DArr(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2DArr(command);
	}
	return (WEXITSTATUS(status));
}
