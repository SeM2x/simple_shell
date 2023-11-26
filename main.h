#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>

extern char **environ;

void print_str(char *str);
size_t scan_str(char **str, size_t *len);
int exec_cmd(char **command, char *main_arg, int len, char **cmd, int attempt);
char **format (char *cmd, size_t len, char sep);
char **get_path(char **env);
char *str_concat(const char *str1, const char *str2);
void free_array(char **array, size_t size);
char *strip(char *str);
char *search_exec(char *command, char *path);
void print_env(char **env);

#endif
