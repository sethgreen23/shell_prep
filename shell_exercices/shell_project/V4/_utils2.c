#include "main.h"
/**
 * _atoi - convert string to integer
 * @n: integer
 *
 * Return: converted integer
 */
char *_atoi(int n)
{
	char buffer[20];
	int i = 0, j, length, n_copy;
	char temp;

	if (n == 0)
		return (_strdup("0"));
	n_copy = n;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (n_copy < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
	length = i - 1;
	i = 0, j = length;
	while (i < j)
	{
		temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
		i++;
		j--;
	}
	return (_strdup(buffer));
}
/**
 * error_print - print error
 * @av: argument array
 * @cmd: wrong command
 * @index: index
 *
 * Return: nothing
*/
void error_print(char **av, char *cmd, int index)
{
	char *str_index = NULL;

	str_index =  _atoi(index);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str_index, _strlen(str_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(str_index);
}
