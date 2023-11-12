#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

/**
 * get_file_path - get the path of a file if it is in $PATH
 * @path: a ptr to the path vector
 * @filename: a char * to the filename
 * return: a char * representing the full path, or NULL
 */

char *get_file_path(char **path, char *filename)
{
    char *current_path;
    struct stat filestats;
    while(is_space(*filename) && *filename)
        filename++;

    if (!*filename)
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

