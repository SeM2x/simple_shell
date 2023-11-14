#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char *getenvvar(char *var, char **env);
int is_space(char c);
char **parse_string(char *str, char separator);
char *cat(char *one, char *two);
char *strip(char *word);
char *get_file_path(char **path, char *filename);
void print_flattened_string(char **v);
size_t _getline(char **str, size_t *len, FILE *stream);
void print_str(char *str);
void spawn_child(char *filepath, char **args, char **env);
void check_filepath(char *filepath, char **args);
char **extend_env(char ***env, char *var);
char **getenvvarptr(char *var, char **env);
char *unset_var(char *var, char ***env);
void setvar(char *varname, char *value, char ***env);
void check_exit(char **args);
#endif
