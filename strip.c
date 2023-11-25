#include "main.h"

/**
 *strip - remove spaces from both sides a string
 *@word: the string
 *
 *Return: a pointer to the striped string.
 */
void strip(char **str)
{
	char *input = *str;
	size_t len = strlen(input);
	char *result = (char*) malloc(len + 1);
	size_t i, j = 0;
	int prev_space = 1;

	if (result == NULL)
	{
		perror("malloc");
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
	
	free(*str);	
	*str = result;
}
