#include "main.h"

/**
 *print_flattened_string - takes a vector (char **), and prints it
 *@v: the vector
 *
 *Return: none
 */
void print_env(char **v)
{
	while (*v)
	{
		print_str(*v++);
		printf("\n");
	}
}
