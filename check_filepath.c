#include "main.h"

/**
 *check_filepath - handle the absence of a file
 *@filepath: the file url
 *@args: the args
 *
 *Return: none
 */
void check_filepath(char *filepath, char **args)
{
	char *error_msg;

	if (!filepath)
	{
		error_msg = cat(args[0], " no program with this name!");
		perror(error_msg);
		free(error_msg);
	}
}
