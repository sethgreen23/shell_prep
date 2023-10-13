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
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
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

	if (arr == NULL)
		return;
	for (; j < position; j++)
		free(arr[j]), arr[j] = NULL;
	free(arr), arr = NULL;
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
			return (_strdup(&environ[i][len + 1]));
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
/**
 * _check_command_valid - check if the command exist or not
 * @command: command to check
 *
 * Return: checked command
*/
char *_check_command_valid(char *command)
{
	char *path = NULL, *abs_path = NULL, *dir = NULL;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	dir = strtok(path, ":");
	while (dir)
	{
		abs_path = malloc(sizeof(char) * (_strlen(dir) + _strlen(command) + 2));
		if (abs_path)
		{
			_strcpy(abs_path, dir);
			_strcat(abs_path, "/");
			_strcat(abs_path, command);
			if (stat(abs_path, &st) == 0)
			{
				free(path);
				return (abs_path);
			}
			free(abs_path), abs_path = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
