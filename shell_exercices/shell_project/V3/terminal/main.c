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
	char *line = NULL;
	int status = 0;

	(void)ac;
	(void)av;
	while (1)
	{
		line = _read_cmd();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		free(line);
	}
	return (0);
}
