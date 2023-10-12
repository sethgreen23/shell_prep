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
	char *line = NULL, **command = NULL;
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
			free(line);
			continue;
		}
		free(line);
		status = _execute(command, av);
	}
	return (status);
}
