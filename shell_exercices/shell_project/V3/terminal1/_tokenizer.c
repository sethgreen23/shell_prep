#include "main.h"
/**
 * _tokenizer - tokenize the command line
 * @line: entered line
 *
 * Return: written line
*/
char **_tokenizer(char *line)
{
	char **cmd = NULL, *line_cp = NULL, *token = NULL;
	int i = 0, len = 0;

	if (line == NULL)
		return (NULL);
	line_cp = _strdup(line);
	token = strtok(line_cp, DELIM);
	if (token == NULL)
	{
		free(line_cp), line_cp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token != NULL)
	{
		len++;
		token = strtok(NULL, DELIM);
	}
	free(line_cp), line_cp = NULL;
	cmd = malloc(sizeof(char *) * (len + 1));
	if (cmd == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	i = 0;
	while (token != NULL)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
