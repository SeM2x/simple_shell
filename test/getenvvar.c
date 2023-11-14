#include "main.h"
#include <stddef.h>

/**
 * getenvvar - get a string representing an env var value
 * @var: a char * value representing the name of the var
 * return: the value of the var in the env
 */

char *getenvvar(char *var, char **env)
{
    size_t i;

    while (*env)
    {
        for (i = 0; var[i] && (*env)[i] && (*env)[i] == var[i]; i++)
            ;
        if ((*env)[i] == '=' && var[i] == '\0')
            return (*env);

        env++;
    }

    return (NULL);
}
