#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;

char *_read_command();
char **_tokenizer(char *line);

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp_limit(char *s1, char *s2, int limit);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

void free2D(char **arr);
void free2DI(char **arr, int position);


#endif
