#include "main.h"

/**
 * exec_cmd - executes a given command
 * @command: the command and its flags
 *
 * Return: Void.
*/
void exec_cmd(char **command)
{
	char **env = environ;
	char **path;
	pid_t pid;
	int status, i;

	path = get_path(env);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		for (i = 0; path[i] != NULL; i++)
		{
			execve(str_concat(path[i], command[0]), command, env);
		}
		perror("execve");
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}
