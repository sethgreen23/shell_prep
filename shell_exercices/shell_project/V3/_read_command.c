#include "main.h"

/**
 * read_command - read the command and argument
 * introduced by the shell
 *
 * Return: command and related arguments
*/
char *read_command(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t ret;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	ret = getline(&cmd, &len, stdin);
	if (ret == -1)
	{
		free(cmd), cmd = NULL;
		return (NULL);
	}
	/*taking out he newLine*/
	if (cmd[ret - 1] == '\n')
		cmd[ret - 1] = '\0';
	return (cmd);
}
