#include "main.h"


void exit_out(int code)
{
	exit(code);
}

int main(int argc, char **argv, char **env) {
    char *line;
    char *filepath;
    size_t letter_count = 100;
    char **args;
		char *error_msg;

    while (1)
    {
        filepath = NULL;
        do
        {
            printf("$ ");
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

						/* handling special functions: exit, env */
						if (!strcmp(line, "env"))
						{
							print_flattened_string(env);
							continue;
						}

						if (!strcmp(line, "exit"))
						{
							printf("exiting ...\n");	
							exit(0);
						}

            filepath = get_file_path(parse_string(getenvvar("PATH", env) + strlen("PATH") + 1, ':'), args[0]);
            if (!filepath)
            {
                error_msg = cat(args[0], " no program with this name!");
                perror(error_msg);
                free(error_msg);
            }
        }
        while (!filepath);

        pid_t child = fork();
        if (child < 0)
        {
            perror("error spawning child\n");
            exit(1);
        }
        else
        {
            /* child is non-zero in the parent process, and zero in the child process */
            /* if (child) == if (we_are_in_parent) */
            if (!child)
                execve(filepath, args, env); /* exec will cause the current executing process to switch to the new one, no need for break */
            else
                waitpid(child, NULL, 0);
        }
    }

    return (0);
}
