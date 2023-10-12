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
