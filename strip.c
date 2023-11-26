#include "main.h"

/**
 *strip - remove spaces from both sides a string
 *@word: the string
 *
 *Return: a pointer to the striped string.
 */
char *strip(char *input)
{
	size_t len = strlen(input);
	char result[1024*1024];
	size_t i, j = 0;
	int prev_space = 1;

	if (result == NULL)
	{
		perror("malloc");
		free(result);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++)
	{
		if (isspace((unsigned char) input[i]))
		{
			if (!prev_space)
			{
				result[j++] = ' ';
				prev_space = 1;
			}
		}
		else
		{
			result[j++] = input[i];
			prev_space = 0;
		}
	}

	if (j > 0 && result[j - 1] == ' ')
	{
		j--;
	}
	

	result[j] = '\0';

	for (i = 0; i < strlen(result); i++)
		if (isspace(result[i]))
		{
			if (result[i + 1] == '#')
				result[i] = '\0';

		}

	return (strdup(result));
}
