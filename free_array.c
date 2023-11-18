#include "main.h"

/**
 * free_array - frees ana rray
 * @array: the array
 * @size: array's length
 *
 * Return: Void.
*/
void free_array(char **array, size_t size)
{
	size_t i;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		free(array[i]);
	}

	free(array);
}
