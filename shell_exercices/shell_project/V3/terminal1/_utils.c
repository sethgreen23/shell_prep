#include "main.h"
/**
 * free2D - free 2D array
 * @arr: array to be freed
 *
 * Return: nothing
*/
void free2D(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}
/**
 * free2DI - free 2D array from position i
 * @arr: array to be freed
 * @position: position i want to start feeing
 *
 * Return: nothing
*/
void free2DI(char **arr, int position)
{
	int j;

	for (; j < position; j++)
		free(arr[j]);
	free(arr);
}
/**
 * _getenv - return the envirement variable value if exist
 * @env_name: name of the envirement variable
 *
 * Return: Nothing
*/
char *_getenv(char *env_name)
{
	int len, i, found;

	len = _strlen(env_name);
	for (i = 0; environ[i] != NULL; i++)
	{
		found = !_strcmp_limit(environ[i], env_name, len) && environ[i][len] == '=';
		if (found)
			return (&environ[i][len + 1]);
	}
	return (NULL);
}
/**
 * _check_command - check if the command exist or not
 * @command: command to check
 *
 * Return: checked command
*/
char *_check_command(char *command)
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
	free(test_char);
	return (NULL);
}
