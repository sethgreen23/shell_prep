#include "main.h"

/**
 * main - main function
 * @ac: argument count
 * @av: argument table
 *
 * Return: 0 on success, 1 on failur
*/
int main(int ac, char **av)
{
	char *line = NULL, **command = NULL, *checked_command = NULL;
	int status = 0;

	(void)ac;
	while (1)
	{
		line = _read_cmd();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = _tokenizer(line);
		if (command == NULL)
		{
			free2D(command);
			free(line);
			continue;
		}
		free(line);
		checked_command = _check_command(command[0]);
		if (checked_command == NULL)
		{
			free2D(command);
			free(checked_command);
			continue;
		}
		command[0] = checked_command;
		status = _execute(command, av);
	}
	return (status);
}
