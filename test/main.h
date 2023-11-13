#ifndef MAIN_H
#define MAIN_H

char *getenvvar(char *var, char **env);
int is_space(char c);
char **parse_string(char *str, char separator);
char *cat(char *one, char *two);
char *strip(char *word);
char *get_file_path(char **path, char *filename);
void *print_flattened_string(char **v);
#endif
