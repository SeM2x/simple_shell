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
	*str = (char *)malloc(*len * sizeof(char));
	if (fgets(*str, *len, stream) == NULL)
	{
		if (!feof(stdin))
			perror("fgets");
		return (0);
	}

	return (strlen(*str));
}
