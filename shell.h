#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
int _put(char characts);
int _prits(const char *string);
void _prop(void);
void _exect(const char *cmd_lines);
void _usrcmd(char **cmder, size_t *sizes);
void _env_print(char **env);
ssize_t _get(char **buffer, size_t *size_s);
#endif
