#include "main.h"

/**
 * tokenizer - tokenize the line from the terminal
 * @cmd: line from the terminal
 *
 * Return: two dimentional array
*/
char **tokenizer(char *cmd)
{
	char *cmd_copy = NULL, *token = NULL, **argv = NULL;
	const char *delim = " \t\n";
	int size = 0, i = 0;

	if (cmd == NULL)
		return (NULL);
	cmd_copy = _strdup(cmd);
	token = strtok(cmd, delim);
	if (token == NULL)
	{
		free(cmd), cmd = NULL;
		free(cmd_copy), cmd_copy = NULL;
		return (NULL);
	}
	while (token != NULL)
	{
		size++;
		token = strtok(NULL, delim);
	}
	free(cmd), cmd = NULL;

	argv = malloc(sizeof(char *) * (size + 1));
	if (argv == NULL)
	{
		free(cmd_copy), cmd_copy = NULL;
		return (NULL);
	}
	token = strtok(cmd_copy, delim);
	i = 0;
	while (token != NULL)
	{
		argv[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	free(cmd_copy), cmd_copy = NULL;
	argv[i] = NULL;
	return (argv);
}
