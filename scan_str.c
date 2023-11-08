#include "main.h"

/**
 * scan_str - scans a string into a variable
 * @str: the string
 * @len: string length
 *
 * Return: Void.
*/
void scan_str(char *str, unsigned int len)
{
	if (fgets(str, len, stdin) == NULL)
	{
		if (feof(stdin))
			print_str("\n");
		else
			perror("fgets");
		exit(1);
	}

	str[strcspn(str, "\n")] = '\0';
}
