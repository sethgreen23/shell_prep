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
int _execute(char **cmd, char **av, int index);
char *_check_command_valid(char *command);
void _print_error(char *prog, char *cmd, int idx);
int verify_built_in(char *cmd);
void handle_builtin_func(char **cmd, int *stat, char **av, int index);
void exit_shell_terminal(char **cmd, int *stat);
void print_env_variable(char **cmd, int *stat);

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp_limit(char *s1, char *s2, int limit);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

void free2D(char **arr);
void free2DI(char **arr, int position);

char *_itoa(int n);
void reverse_str(char *str, int length);

#endif
