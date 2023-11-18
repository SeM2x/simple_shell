#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
*/
int main(int argc, char **argv)
{
	char command[100];
	char **av;

	if (argc < 0)
		return (1);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str("#simple_shell$ ");
		scan_str(command, 100);
		av = format(command, ' ');
		if (feof(stdin))
			break;
		if (av[0][0] != '\0')
		{
			if (strcmp(av[0], "exit") == 0)
				break;
			if (av != NULL)
				exec_cmd(av, argv[0]);
		}
		if (av != NULL)
			free_array(av);
	}

	if (av != NULL)
		free_array(av);
	return (0);
}
