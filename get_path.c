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
	size_t len = 0;
	
	for (i = 0; env[i] != NULL; i++)
		len++;
	for (i = 0; i < (int) len; i++)
	{
		if (strstr(env[i], "PATH"))
		{
			path = format(env[i], len, ':');
			break;
		}
	}

	for (i = 0; path[i] != NULL; i++)
	{
		path[i][strlen(path[i])] = '/';
	}
	return (path);
}
