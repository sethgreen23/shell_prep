#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

char *read_command(void);
char **tokenizer(char *line);
void print2DArr(char **arr);
void free2DArr(char **arr);
int _execute(char **command, char **argv);

char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif /*END IF*/

