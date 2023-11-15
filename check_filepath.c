#include "main.h"

/**
 *check_filepath - handle the absence of a file
 *@filepath: the file url
 *@args: the args
 *
 *Return: none
 */
void check_filepath(char *filepath, char **args, char *arg_0)
{
	char *error_msg;

	if (!filepath)
	{
		error_msg = cat(arg_0, ": ");
		error_msg = cat(error_msg, "1: ");
		error_msg = cat(error_msg, args[0]);
		error_msg = cat(error_msg, ": ");
		error_msg = cat(error_msg, "not found\n");
		print_str(error_msg);
		free(error_msg);
	}
}
