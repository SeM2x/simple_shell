#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
*/
int main(void)
{
	char *av[2];

	av[0] = malloc(100 * sizeof(char));
	av[1] = NULL;
	while (1)
	{
		print_str("#hsh$ ");
		scan_str(av[0], 100);
		exec_cmd(av);
	}

	return (0);
}
