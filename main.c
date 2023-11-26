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
	char *tmp, *command = "\0";
	char **av;
	char **env = environ;
	int i, count = 0, attempt = 0;
	size_t size = 0;
	int status = 0;

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
	
		if (command[0] == '\0')
			continue;	
			
		count = 1;
		for (i = 0; i < (int) strlen(command); i++)
		{
			if (command[i] == ' ')
				count++;
		}

		av = format(command, count, ' ');

		if (strcmp(av[0], "exit") == 0)
		{
			free(command);

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
		else if (av != NULL)
			status = exec_cmd(av, argv[0], count, &command, attempt);

		free_array(av, count);
		
	}

	free(command);
	exit(status);

	return (0);
}
