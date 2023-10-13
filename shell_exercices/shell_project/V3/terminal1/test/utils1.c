#include "main.h"
/**
 * _strdup - copy the string given as a parameter
 * @str: string
 *
 * Return: pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int i;
	unsigned int size;

	if (str == NULL)
		return (NULL);
	size = _strlen(str);
	copy = malloc((size * sizeof(char)) + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		copy[i] = str[i];
	}
	copy[i] = '\0';
	return (copy);
}
/**
 * check_command - check if the command exist or not
 * @command: command to check
 *
 * Return: checked command
*/
char *check_command(char *command)
{
	char *key = "PATH", *copy_env = NULL, *token = NULL, *test_char = NULL;
	struct stat st;

	if (command[0] == '/')
	{
		if (!stat(command, &st))
		{
			test_char = _strdup(command);
			return (test_char);
		}
		else
			return (NULL);
	}
	copy_env = _strdup(_getenv(key));
	if (copy_env == NULL)
		return (NULL);

	token = strtok(copy_env, ":");
	if (token == NULL)
	{
		free(copy_env);
		return (NULL);
	}
	while (token)
	{
		test_char = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
		_strcpy(test_char, token);
		_strcat(test_char, "/");
		_strcat(test_char, command);
		if (!stat(test_char,  &st))
		{
			free(copy_env);
			return (test_char);
		}
		token = strtok(NULL, ":");
	}
	free(copy_env);
	return (test_char);
}
