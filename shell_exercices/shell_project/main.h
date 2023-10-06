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
char *_evaluate(char *cmd);
int _getline();
void _tokenizer(char *cmd);
int _execve(char *pathname, char*argv[]);

#endif