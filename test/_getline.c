#include "main.h"

/**
 *_getline - scans a string into a variable
 *@str: the string
 *@len: string length
 *@stream: the stream
 *
 *Return: Number of read character.
 */
size_t _getline(char **str, size_t *len, FILE *stream)
{
	char tmp[100];

	if (fgets(tmp, *len, stream) == NULL)
	{
		if (!feof(stdin))
			perror("fgets");
		*str = NULL;
		return (0);
	}
	*str = strdup(tmp);
	return (strlen(*str));
}
