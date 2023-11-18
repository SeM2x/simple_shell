#include "main.h"

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
