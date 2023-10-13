#include "main.h"

/**
 * main - Main function for Simple shell
 * @ac: argument count
 * @av: program arguments
 *
 * Return: 0 is succes, 1 if fails
*/
int main(int ac, int **av)
{
	char *line = NULL;
	char **cmd = NULL;
	int stat = 0;

	(void)ac;
	while (1)
	{
		line = _read_command();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		cmd = _tokenizer(line);
		if (cmd == NULL)
			continue;
		free2D(cmd), cmd = NULL;
	}
	return (stat);
}
