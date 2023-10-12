#include "main.h"
/**
 * _execute - tokenize the command line
 * @command: entered line
 * @av: argument table
 *
 * Return: written line
*/
int _execute(char **command, char **av)
{
	pid_t child_pid;
	int status = 0;

	if (command == NULL || av == NULL)
		return (0);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			free2D(command);
			exit (127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2D(command);
	}
	return (WEXITSTATUS(status));
}
/**
 * int main (int ac, char **av)
{
	char line[12] = "/bin/l -la", **command = NULL;
	int status = 0;

	(void)ac;
	command = _tokenizer(line);
	if (command == NULL)
	{
		printf("command is not tokenized\n");
		return (status);
	}
	status = _execute(command, av);
	free2D(command);
	return (status);
}

 * 
 * 
*/
