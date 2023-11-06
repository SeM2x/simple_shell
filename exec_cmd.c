#include "main.h"

/**
 * exec_cmd - executes a given command
 * @command: the command and its flags
 *
 * Return: Void.
*/
void exec_cmd(char **command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(command[0], command, NULL) < 0)
			perror("execve");
		exit(1);
	}
	waitpid(pid, &status, 0);
}
