#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

void print_str(char *str);
void scan_str(char *str, unsigned int len);
void exec_cmd(char **command, char *main_arg);
char **format (char *cmd, char sep);
char **get_path(char **env);
char *str_concat(const char *str1, const char *str2);

#endif
