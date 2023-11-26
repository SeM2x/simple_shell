#include "main.h"

/**
 * exec_cmd - executes a given command
 * @command: the command and its flags
 * @main_arg: arg[0] of the main function
 * @len: length of command
 *
 * Return: Void.
*/
int exec_cmd(char **command, char *main_arg, int len, char **cmd, int count)
{
	char **env = environ, *exec_path;
	pid_t pid;
	int status = 0;
	char *path = getenv("PATH");
	if (!path)
		path = "";

	exec_path = search_exec(command[0], path);

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		execve(command[0], command, env);
		if (exec_path)
		{
			execve(exec_path, command, env);
			perror(main_arg);
		}
		else
			fprintf(stderr, "%s: %d: %s: not found\n",
                                        main_arg, count, command[0]);	
		free_array(command, len);
		free(*cmd);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(exec_path);
		if (WIFEXITED(status)) {
			return (WEXITSTATUS(status));
		}
		/*free(path);*/
	}

	return (status);
}
