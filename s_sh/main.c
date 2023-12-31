#include "main.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: 0
*/
int main(int argc, char **argv)
{
	char *tmp, *command = "\0", cwd[1024];
	char **av, **commands;
	char **env = environ;
	int i, count = 0, attempt = 0, c = 1;
	size_t size = 0, cwd_size = sizeof(cwd);
	int status = 0, cd_status = 0;

	av = NULL;

	if (argc < 0)
		return (1);

	while (1)
	{
		attempt++;
		if (isatty(STDIN_FILENO))
			print_str("#simple_shell$ ");
		scan_str(&command, &size);
		if (feof(stdin))
			break;
		tmp = strip(command);
		strcpy(command, tmp);
		free(tmp);
		
		for (i = 0; i <  (int) strlen(command); i++)
			if (command[i] == ';')
				c++;

		commands = format(command, c, ';');
		for (i = 0; i < c; i ++)
			printf("===%s===\n", commands[c]);
		free(command);
		do {
		if (commands[c][0] == '\0')
			continue;	
			
		count = 1;
		for (i = 0; i < (int) strlen(commands[c]); i++)
		{
			if (commands[c][i] == ' ')
				count++;
		}

		av = format(commands[c], count, ' ');

		/*if (strcmp(av[0], "exit") == 0)
		{
			free(commands[c]);

			if (av[1])
			{
				if (is_positive(av[1]))
					status = atoi(av[1]);
				else
				{
					fprintf(stderr, "%s: %d: %s: Illegal number: %s\n",
						argv[0], attempt, av[0], av[1]);
					status = 2;
				}
			}

			free_array(av, count);
			exit(status);
		}
		else if (strcmp(av[0], "env") == 0)
			print_env(env);

		else if (strcmp(av[0], "setenv") == 0)
		{
			if (av[1] && av[2])
				setenv(av[1], av[2], 1);
			env = environ;
		}	
		else if (strcmp(av[0], "unsetenv") == 0)
		{
			if (av[1])
				unsetenv(av[1]);
			env = environ;
		}
		else if (strcmp(av[0], "cd") == 0)
		{	
			getcwd(cwd, cwd_size);
			if (av[1])
			{
				if (!strcmp(av[1], "-"))
				{
					if (getenv("OLDPWD"))
					{
						cd_status = chdir(getenv("OLDPWD"));
						print_str(getenv("OLDPWD"));
					}
					else
						print_str(cwd);
					print_str("\n");
				}
				else
				{
					cd_status = chdir(av[1]);
					if(cd_status)
					{
						fprintf(stderr, "%s: %d: %s: can't cd to %s\n",
							argv[0], attempt, av[0], av[1]);
					}
				}
					
			}
			else
				if (getenv("HOME"))
					cd_status = chdir(getenv("HOME"));
			if (!cd_status)
			{
				setenv("OLDPWD", cwd, 1);
				setenv("PWD", getcwd(cwd, cwd_size), 1);
			}
		}
		else */if (av != NULL)
			status = exec_cmd(av, argv[0], count, &commands[c], attempt);
		free_array(av, count);

		c++;
		} while (commands[c]);

		free(commands);
	}

	free(command);
	exit(status);

	return (0);
}
