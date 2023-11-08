#include "main.h"

/**
 * get_path - splits the PATH env variable into an array.
 * @env: the eviron
 *
 * Return: a pointer to the array.
*/
char **get_path(char **env)
{
	char **path;
	int i;

	path = malloc(20 * sizeof(char *));
	if (path == NULL)
		return (NULL);
	for (i = 0; env[i] != NULL; i++)
	{
		if (strstr(env[i], "PATH"))
		{
			path = format(env[i], ':');
			break;
		}
	}

	for (i = 0; path[i] != NULL; i++)
	{
		path[i][strlen(path[i])] = '/';
	}
	return (path);
}
