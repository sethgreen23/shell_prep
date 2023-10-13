#include "main.h"

/**
 * verify_built_in - verify if command is builtin
 * @cmd: command to verify
 *
 * Return: nothing
*/
int verify_built_in(char *cmd)
{
	char *builtins[] = {
		"exit", "env", NULL
	};
	int i;

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin_func - handle builtin function
 * @cmd: command line array
 * @stat: status of the last command
 * @av: argument table
 * @index: index of the line
 *
 * Return: nothing
*/
void handle_builtin_func(char **cmd, int *stat, char **av, int index)
{
	(void)av;
	(void)index;

	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell_terminal(cmd, stat);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env_variable(cmd, stat);
}
/**
 * exit_shell_terminal - exit shell
 * @cmd: command array
 * @stat: status
 *
 * Return: nothing
*/
void exit_shell_terminal(char **cmd, int *stat)
{
	free2D(cmd);
	exit(*stat);
}
/**
 * print_env_variable - print env variable
 * @cmd: command array
 * @stat: status
*/
void print_env_variable(char **cmd, int *stat)
{
	int i;

	(void) stat;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2D(cmd);
	*stat = 0;
}
