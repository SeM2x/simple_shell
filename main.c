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
			free_array(av, count);
			free(command);
			exit(status);
		}
		if (av != NULL)
			status = exec_cmd(av, argv[0], count, &command, attempt);

		free_array(av, count);
		
	}

	free(command);
	exit(status);

	return (0);
}
