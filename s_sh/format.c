#include "main.h"

/**
 *format - splits a string into an array
 *@cmd: the string
 *@sep: separator
 *
 *Return: a pointer to the array or NULL.
 */
char **format(char *cmd, size_t len, char sep)
{
	size_t i;
	int j, k;
	char *buff = NULL;
	char **tmp;
	
	if (!cmd)
		return (NULL);
	j = 0;
	k = 0;

	tmp = malloc((len + 1) * sizeof(char *));

	for (i = 0; i < strlen(cmd) + 1; i++)
	{
		if (cmd[i] == sep || cmd[i] == '\0')
		{
			tmp[k] = malloc((j + 1) * sizeof(char));
			buff[j] = '\0';
			strcpy(tmp[k], buff);
			k++;
			j = 0;
			free(buff);
			buff = NULL;
		}
		else
		{
			buff = realloc(buff, (j + 2) * sizeof(char));
			buff[j] = cmd[i];
			j++;
		}
	}

	tmp[len] = NULL;
	free(buff);

	return (tmp);
}
