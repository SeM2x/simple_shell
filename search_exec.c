#include "main.h"

char *search_exec(char *command, char *path)
{
	char *token;
	char *path_copy = strdup(path);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char *executable_path = malloc(strlen(token) + strlen(command) + 2);
		strcpy(executable_path, token);
		strcat(executable_path, "/");
		strcat(executable_path, command);

		if (access(executable_path, X_OK) == 0)
		{
			free(path_copy);
			return (executable_path);
		}

		free(executable_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
