#include "main.h"

/**
 *get_file_path - get the path of a file if it is in $PATH
 *@path: a ptr to the path vector
 *@filename: a char *to the filename
 *
 *Return: a char *representing the full path, or NULL
 */
char *get_file_path(char **path, char *filename)
{
	char *current_path;
	struct stat filestats;
	size_t current_letter;

	for (current_letter = 0; filename[current_letter]; current_letter++)
		if (filename[current_letter] == '/')
			return (filename);

	while (is_space(*filename) && *filename)
		filename++;

	if (!(*filename))
		return (NULL);
	while (*path)
	{
		current_path = cat(cat(*path, "/"), filename);
		if (!stat(current_path, &filestats))
			return (current_path);

		path++;
	}

	return (NULL);
}
