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
	{
		print_str(*v++);
		printf("\n");
	}
}
