#include "main.h"

char **extend_env(char ***env, char *var)
{
	size_t count, counter;
	char **new_env;

	for (count = 0; (*env)[count]; count++);
	
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return (NULL);

	for (counter = 0; counter < count; counter++)
		new_env[counter] = (*env)[counter];

	/* new_env[counter] = strdup(var); -> this causes segfault in c89 */
	new_env[counter] = cat(var, "");
	printf("newly added variable: %s\n", new_env[counter]);
	printf("here goes the seg fault:\nnew_env[%lu] = %s\n", counter, new_env[counter]);
	new_env[counter + 1] = NULL;
	*env = new_env;
	return (new_env);
}
