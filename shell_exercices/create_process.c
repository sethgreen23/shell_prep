#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t child_pid; /*The process ID of the child process*/

    /*Create a new process*/
    child_pid = fork();

    if(child_pid == -1)
    {
        perror("fork failed\n");
        return (1);
    }

    if (child_pid == 0)
    {
        /*We are in the child process*/
        printf("Child process is running\n");
    }
    else
    {
        /*We are in the parent process*/
        printf("Parent process is running\n");
    }

    return (0);
}