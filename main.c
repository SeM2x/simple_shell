#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
*/
int main(void)
{
	char command[100];
	char **av;

	while (1)
	{
		print_str("#simple_shell$ ");
		scan_str(command, 100);
		av = format(command, ' ');
		if (av[0][0] != '\0')
		{
			if (strcmp(av[0], "exit") == 0)
				exit(0);
			exec_cmd(av);
		}
	}

	return (0);
}
