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
	char *line;
	char *filepath;
	size_t letter_count = 100;
	char **args;

	while (1)
	{
		filepath = NULL;
		do {
			print_str("$ ");
			_getline(&line, &letter_count, stdin);
			if (feof(stdin))
				print_str("\n");
			if (!line[0])
				exit(0);

			line[strlen(line) - 1] = 0;
			line = strip(line);
			args = parse_string(line, ' ');
			if (!args)
				continue;
			if (!strcmp(line, "env"))
			{
				print_flattened_string(env);
				continue;
			}

			check_exit(args);
			filepath = get_file_path(
					parse_string(getenvvar("PATH", env) + strlen("PATH") + 1, ':'), args[0]
					);
			check_filepath(filepath, args);
		}

		while (!filepath);
		spawn_child(filepath, args, env);
	}

	return (0);
}
