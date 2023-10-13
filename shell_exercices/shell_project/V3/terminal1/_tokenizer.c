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
	if (line_cp == NULL)
		return (NULL);
	token = strtok(line_cp, DELIM);
	if (token == NULL)
	{
		free(line_cp);
		return (NULL);
	}
	while (token != NULL)
	{
		len++;
		token = strtok(NULL, DELIM);
	}
	free(line_cp);
	cmd = malloc(sizeof(char *) * (len + 1));
	if (cmd == NULL)
		return (NULL);
	token = strtok(line, DELIM);
	i = 0;
	while (token != NULL)
	{
		cmd[i] = _strdup(token);
		if (cmd[i] == NULL)
		{
			free2DI(cmd, i);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
