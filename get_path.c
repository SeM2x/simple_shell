#include "main.h"

/**
 * get_path - splits the PATH env variable into an array.
 * @env: the eviron
 *
 * Return: a pointer to the array.
*/
char **get_path(char **env)
{
	char **path = malloc(3 * sizeof(char *));
	path[0] = malloc(4);
	strcpy(path[0], "yes");
	path[1] = malloc(4);
	strcpy(path[1], "huh");
	path[2] = NULL;

	if (!env)
		return NULL;
	/*
	int i, j;
	size_t len = 1;

	for (i = 0; env[i]; i++)
	{
		if (strstr(env[i], "PATH"))
		{
			for (j = 0; j < (int) strlen(env[i]); j++)
				if (env[i][j] == ':')
					len++;
			printf("pathlen: %ld\n", len);
			path = format(env[i] + 4, len, ':');
			path[len] = NULL;
			break;
		}
	}

	for (i = 0; path[i] != NULL; i++)
	{
		path[i][strlen(path[i])] = '/';
	}
	*/
	return (path);
}
