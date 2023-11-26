#include "main.h"

/**
 * scan_str - scans a string into a variable
 * @str: the string
 * @len: string length
 *
 * Return: Void.
*/
size_t scan_str(char **str, size_t *len)
{
	size_t length;

	length = getline(str, len, stdin);
	if ((int)length == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				print_str("\n");
		}
		else
			perror("getline");
	}
	
	return (length);	
}
