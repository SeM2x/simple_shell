#include "main.h"

/**
 * exec_cmd - executes a given command
 * @command: the command and its flags
 * @main_arg: arg[0] of the main function
 * @len: length of command
 *
 * Return: Void.
*/
void exec_cmd(char **command, char *main_arg, int len, char **cmd)
{
	char **env = environ;
	pid_t pid;
	int status;
	char *path = getenv("PATH");
	char *exec_path = search_exec(command[0], path);

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		if (command[0][0] == '/')
			execve(command[0], command, env);
		else
		{
			if (exec_path != NULL)
				execve(exec_path, command, env);
		}
		perror(main_arg);
		free_array(command, len);
		free(*cmd);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		/*free(path);*/
		free(exec_path);
	}
}
