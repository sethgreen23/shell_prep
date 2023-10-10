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
