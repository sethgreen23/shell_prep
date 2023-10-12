#ifndef MAIN_H
#define MAIN_H
#define DELIM "\t\n "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
extern char **environ;

char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp_limit(char *s1, char *s2, int limit);
char *_getenv(char *env_name);


#endif
