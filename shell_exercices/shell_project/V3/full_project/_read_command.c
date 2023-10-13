#include "main.h"

/**
 * _read_command - read the command from input
 *
 * Return: read command or NULL if impossible
*/
char *_read_command()
{
	char *line = NULL;
	size_t length = 0;
	ssize_t chars_number;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	chars_number = getline(&line, &length, stdin);
	if (chars_number == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
