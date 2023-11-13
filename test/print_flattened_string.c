#include <stdio.h>
#include "main.h"
/**
 * print_flattened_string - takes a vector (char **), and prints it
 * @v: the vector
 * return: none
 */

void *print_flattened_string(char **v)
{
	while(*v)
		printf("%s\n", *v++);
}
