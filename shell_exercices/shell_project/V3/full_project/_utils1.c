#include "main.h"

/**
 * _print_error - print custom error
 * @prog: name of the program
 * @cmd: wrong command
 * @idx: the index
 *
 * Return: nothing
*/
void _print_error(char *prog, char *cmd, int idx)
{
	char *number;
	char message[] = ": not found\n";

	number = _itoa(idx);
	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, message, _strlen(message));
	free(number);
}

/**
 * _itoa - change int to string
 * @n: number to stringify
 *
 * Return: stringified integer
*/
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_str - reverse a string
 * @str: string to reverse
 * @length: length of the string
 *
 * Return: the reversed string
*/
void reverse_str(char *str, int length)
{
	char tmp;
	int begin = 0;
	int end = length - 1;

	while (begin < end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}

