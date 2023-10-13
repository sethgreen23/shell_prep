#include "main.h"
#define DELIMITER " \t\n"
/**
 * _tokenizer - tokenize the command line
 * @line: the line to be tokenized
 *
 * Return: command with attribute or NULL
*/
char **_tokenizer(char *line)
{
	char *token = NULL, **cmd = NULL, *line_cpy = NULL;
	int length = 0, i;

	if (line == NULL)
		return (NULL);
	line_cpy = _strdup(line);
	token = strtok(line_cpy, DELIMITER);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(line_cpy), line_cpy = NULL;
		return (NULL);
	}
	while (token)
	{
		length++;
		token = strtok(NULL, DELIMITER);
	}
	free(line_cpy), line_cpy = NULL;
	cmd = malloc(sizeof(char *) * (length + 1));
	if (cmd == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIMITER);
	i = 0;
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
