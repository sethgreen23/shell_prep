#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **split_str(char *cmd, const char *delim);
char *_strtok(char *str, const char *delim);
#endif