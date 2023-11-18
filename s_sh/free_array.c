#include "main.h"

void free_array(char **array)
{
	size_t i;

    if (array == NULL) {
        return;
    }

    for (i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }

    free(array);
}
