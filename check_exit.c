#include "main.h"

/**
 *check_exit - chek if user wants to exit
 *@args: the words that the user typed
 */
void check_exit(char **args)
{
	if (!strcmp(args[0], "exit"))
	{
		printf("exiting ...\n");
		if (args[1])
			exit(atoi(args[1]));
		exit(0);
	}
}
