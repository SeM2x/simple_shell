#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void print_str(char *str);
void scan_str(char *str, unsigned int len);
void exec_cmd(char **command);

#endif
