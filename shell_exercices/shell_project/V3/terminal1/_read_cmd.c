#include "main.h"
/**
 * _read_cmd - read the command line
 *
 * Return: written line
*/
char *_read_cmd()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_char = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n_char = getline(&line, &len, stdin);
	if (n_char == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	if (line[_strlen(line) - 1] == '\n')
		line[_strlen(line) - 1] = '\0';
	return (line);
}
