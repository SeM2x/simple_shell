#include "main.h"

/**
 *getenvvarptr - get a string representing an env var value
 *@var: a char *value representing the name of the var
 *@env: the environ
 *
 *Return: the value of the var in the env
 */
char **getenvvarptr(char *var, char **env)
{
	size_t i;

	while (*env)
	{
		for (i = 0; var[i] && (*env)[i] && (*env)[i] == var[i]; i++)
			;
		if ((*env)[i] == '=' && var[i] == '\0')
			return (env);

		env++;
	}

	return (NULL);
}
