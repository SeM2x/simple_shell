#include "main.h"

/**
 *main - the starting point.
 *@argc: arguments count.
 *@argv: the arguments array.
 *@env: the enironment array.
 *
 *Return: 0.
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL, *filepath = NULL, **args = NULL, *cwd = NULL, **parsed_string = NULL;
	size_t letter_count = 100, cwd_size = 50;
	int status, i;

	if (!argc)
		return (1);

	cwd = malloc(cwd_size * sizeof(char));
	while (1)
	{
		filepath = NULL;
		do {
			if (isatty(STDIN_FILENO))
				print_str("$ ");
			_getline(&line, &letter_count, stdin);
			if (feof(stdin))
			{
				print_str("\n");
				break;
			}

			line[strlen(line) - 1] = 0;
			line = strip(line);
			args = parse_string(line, ' ');
			if (!args)
				continue;

			/* here's the setenv buisness */
			if (!strcmp("setenv", args[0]))
			{
				setvar(args[1], args[2], &env);
				continue;	
			}

			if (!strcmp("unset", args[0]))
			{
				unset_var(args[1], &env);
				continue;	
			}

			if (!strcmp(line, "env"))
			{
				print_flattened_string(env);
				continue;
			}
			if (!strcmp(args[0], "cd"))
			{
				getcwd(cwd, cwd_size);
				if (args[1])
				{
					if (!strcmp(args[1], "-"))
						status = chdir(getenvvar("OLDPWD", env) + 7);
					else
						status = chdir(args[1]);
				}
				else
					status = chdir(getenvvar("HOME", env) + 5);
				if (!status)
				{
					setvar("OLDPWD", cwd, &env);
					setvar("PWD", getcwd(cwd, cwd_size), &env);
				}
				continue;
			}

			check_exit(args);
			parsed_string = parse_string(getenvvar("PATH", env) + strlen("PATH") + 1, ':');
			filepath = get_file_path(parsed_string, args[0]);
			check_filepath(filepath, args, argv[0]);
		}
		while (!filepath);
		if (feof(stdin))
			break;
		spawn_child(filepath, args, env);

	}
	free(cwd);
	free(line);
	free(filepath);
	if (parsed_string)
	{
		for (i = 0; parsed_string[i]; i++)
			free(parsed_string[i]);
	}
	if (args)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
	}
	return (0);
}
