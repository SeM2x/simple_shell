#include "main.h"

/**
 *spawn_child - forks a process
 *@filepath: the filepath
 *@args: the args
 *@env: the environ
 *
 *Return: Void.
 *
 */
void spawn_child(char *filepath, char **args, char **env)
{
	pid_t child = fork();

	if (child < 0)
	{
		perror("error spawning child\n");
		exit(1);
	}
	else
	{
		/*child is non-zero in the parent process, and zero in the child process */
		/*if (child) == if (we_are_in_parent) */
		if (!child)
			execve(filepath, args, env);

		else
			waitpid(child, NULL, 0);
	}
}
