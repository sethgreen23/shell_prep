#include "main.h"

/**
 * main - main function the shell project
 * @ac: arguments count
 * @av: arguments array
 *
 * Return: 0 on success, 1 on fails
*/
int main(int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;

	(void)ac;
	while (1)
	{
		/*Read line from the promp*/
		line = read_command();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = tokenizer(line);
		if (command == NULL)
			continue;
		status = _execute(command, av);
	}
	return (0);
}
