#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
*/
int main(int argc, char **argv)
{
	char command[100] = "\0";
	char **av;
	int i, count;

	av = NULL;
	
	if (argc < 0)
		return (1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str("#simple_shell$ ");
		scan_str(command, 100);
		strip(command);
		av = format(command, ' ');
		if (feof(stdin))
			break;
		count = 1;
                for (i = 0; i < (int)strlen(command) ; i++)
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
				exec_cmd(av, argv[0], count);
		}

		free_array(av, count + 1);

	}

	free(av[0]);
	free(av);
	return (0);
}
