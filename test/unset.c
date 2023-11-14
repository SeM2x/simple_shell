#include "main.h"
#include <stddef.h>

/**
 * unset_var - get a string representing an env var value
 * @var: a char * value representing the name of the var
 * return: the value of the var in the env
 */

char *unset_var(char *var, char ***env)
{
    size_t i, j;

    for (j = 0; (*env)[j]; j++)
    {
        for (i = 0; var[i] && (*env)[j][i] && (*env)[j][i] == var[i]; i++)
            ;


        if ((*env)[j][i] == '=' && var[i] == '\0')
        {
            i = j; /* saving the index of the jth element in the var i to return it */
            for (; (*env)[j]; j++)
                (*env)[j] = (*env)[j + 1];

            return ((*env)[i]);
        }
    }

    return (NULL);
}
