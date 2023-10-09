#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

char *_read_cmd();
char **_tokenizer(char *line);
int _execute(char **command, char **av);

int _strlen(char *s);

#endif
