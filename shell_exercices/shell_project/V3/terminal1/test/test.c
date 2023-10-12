#include "main.h"
/**
 * main - main function
 *
 * Return: nothing
*/
int main(void)
{
	int i, j;
	size_t n = 4;
	char *key = "PATH";
	char *command = "ls";
	char *copy_env = NULL, *token = NULL;
	char *test_char = NULL, *env = NULL;
	struct stat st;

	copy_env = _strdup(_getenv(key));
	if (copy_env == NULL)
	{
		return (1);
	}

	token = strtok(copy_env, ":");
	if (token == NULL)
	{
		free(copy_env);
		return (1);
	}
	while (token)
	{
		test_char = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
		_strcpy(test_char, token);
		_strcat(test_char, "/");
		_strcat(test_char, command);
		if (!stat(test_char,  &st))
		{
			printf("%s is a linux command\n", command);
			printf("%s is a good path\n", test_char);
			free(test_char);
			free(copy_env);
			return (0);
		}
		token = strtok(NULL, ":");
		free(test_char);
	}
	printf("%s is not a linux command\n", command);
	free(copy_env);
	return (0);
}
