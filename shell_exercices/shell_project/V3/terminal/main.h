#ifndef MAIN_H
#define MAIN_H
#define DELIM "\t\n "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char **environ;

char *_read_cmd();
char **_tokenizer(char *line);
int _execute(char **command, char **av);

int _strlen(char *s);
char *_strdup(char *str);

void free2D(char **arr);
void free2DI(char **arr, int position);

#endif
