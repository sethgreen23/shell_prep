#include "main.h"
/**
 * free2DArr - free a 2 Dimentional Array
 * @arr: array to free
 *
 * Return: Nothing
*/
void free2DArr(char **arr)
{
	int i = 0;

	for (; arr[i] != NULL; i++)
	{
		free(arr[i]), arr[i] = NULL;
	}
	free(arr);
}
/**
 * print2DArr - print a 2 Dimentional Array
 * @arr: array to free
 *
 * Return: Nothing
*/
void print2DArr(char **arr)
{
	int i = 0;

	for (; arr[i] != NULL; i++)
	{
		printf("[%d] %s\n", i, arr[i]);
	}
}
