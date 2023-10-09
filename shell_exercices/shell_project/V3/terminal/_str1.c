#include "main.h"

/**
 * _strlen - return the length of a string
 * @s: pointer to a string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
	;
	return (len);
}
