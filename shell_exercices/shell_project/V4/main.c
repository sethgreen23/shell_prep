#include "main.h"

/**
 * main - main function
 * @ac: argument count
 * @av: argument table
 *
 * Return: nothing
*/
int main(int ac, char **av)
{
	char *line = NULL, **command = NULL;
	int status = 0, index = 0;
	(void) ac;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		command = _tokenizer(line);
		if (command == NULL)
			continue;
		status = execute(command, av, index);
	}
}
