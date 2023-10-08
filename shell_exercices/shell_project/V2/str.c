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
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		copy[i] = str[i];
	}
	copy[i] = '\0';
	return (copy);
}

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

/**
 * _strcpy - copy the string from source to destination including
 * the null (\0) byte
 * @dest: destination character array
 * @src: source character array
 *
 * Return: array of characters
 */
char *_strcpy(char *dest, char *src)
{
	char *original_dest, *original_src;

	original_dest = dest;
	original_src = src;
	for (; *original_src != '\0'; original_src++, original_dest++)
		*original_dest = *original_src;
	*original_dest = '\0';
	return (dest);
}

