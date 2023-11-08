#include "main.h"

/**
 *format - splits a string into an array
 *@cmd: the string
 *@sep: separator
 *
 *Return: a pointer to the array or NULL.
 */
char **format(char *cmd, char sep)
{
	size_t i;
	int j, k;
	char buff[20];
	char **tmp;

	buff[0] = '\0';
	j = 0;
	k = 0;

	tmp = malloc(20 * sizeof(char *));
	if (tmp == NULL)
		return (NULL);

	for (i = 0; i < strlen(cmd) + 1; i++)
	{
		if (cmd[i] == sep || cmd[i] == '\0')
		{
			tmp[k] = malloc(100 * sizeof(char));
			if (tmp[k] == NULL)
				return (NULL);
			buff[j] = '\0';
			tmp[k] = strdup(buff);
			k++;
			j = 0;
		}
		else
		{
			buff[j] = cmd[i];
			j++;
		}
	}

	return (tmp);
}
