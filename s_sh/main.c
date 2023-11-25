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
	char *command;
	char **av;
	int i, count;
	
	command = malloc (100 * sizeof(char));
	av = NULL;

	if (argc < 0)
		return (1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str("#simple_shell$ ");
		scan_str(&command, 1024);
		if (feof(stdin))
			break;
		av = format(command, ' ');
		count = 1;
		for (i = 0; i < (int) strlen(command); i++)
		{
			if (command[i] == ' ')
				count++;
		}

		av[count] = NULL;
		if (av[0][0] != '\0')
		{
			if (strcmp(av[0], "exit") == 0)
				break;
			if (av != NULL)
				exec_cmd(av, argv[0], count, &command);
		}
		
		free_array(av, count + 1);
	}
	free(command);
	return (0);
}
