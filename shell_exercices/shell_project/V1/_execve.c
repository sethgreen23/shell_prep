#include "main.h"

int _execve(char *pathname, char*argv[])
{
    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        perror("failed to create a process\n");
        return(1);
    }

    if (pid == 0)
    {
        if (execve(pathname, argv, NULL) == -1)
        {
            perror("failed to excute the command\n");
            return(1);
        }
    }else
    {
        wait(NULL);
    }
    return(0);
}