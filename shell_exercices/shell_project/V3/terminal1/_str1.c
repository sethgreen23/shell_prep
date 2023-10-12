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
 * _strcmp_limit - compare two strings
 * @s1: first string
 * @s2: second string
 * @limit: limit
 *
 * Return: value less, equal or less than 0 if s1 is found
 */
int _strcmp_limit(char *s1, char *s2, int limit)
{
	while (limit > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			break;
		s1++;
		s2++;
		limit--;
	}
	return (0);
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
/**
 * _strcat - concatenate two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: result of concatenation
 */
char *_strcat(char *dest, char *src)
{
	char *dest_clone, *src_clone;

	dest_clone = dest, src_clone = src;
	for (; *dest_clone != '\0'; dest_clone++)
		;
	for (; *src_clone != '\0'; src_clone++, dest_clone++)
	{
		*dest_clone = *src_clone;
	}
	*dest_clone = '\0';
	return (dest);
}
