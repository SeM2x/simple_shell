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
	/*char **path;*/
	pid_t pid;
	int status;

	/*path = get_path(env);*/
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		execve(command[0], command, env);
		/**
		* for (i = 0; path[i] != NULL; i++)
		*	{
		*	tmp = str_concat(path[i], command[0]);
		*	execve(tmp, command, env);
		* }
		*/
		perror(main_arg);
		free_array(command, len);
		free(*cmd);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	/*free_array(path);*/
}
