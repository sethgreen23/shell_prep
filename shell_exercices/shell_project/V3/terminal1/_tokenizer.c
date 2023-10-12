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

/**
 * int main (void)
{
	char line[12] = "hello world", **command = NULL;
	int i = 0;


	command = _tokenizer(line);
	if (command == NULL)
	{
		printf("command is not tokenized\n");
		need to free lien
		return (0);
	}
		need to free lien
	for (; command[i] != NULL; i++)
	{
		printf("%s\n", command[i]);
	}
	free2D(command);
	return (0);
}

*/
