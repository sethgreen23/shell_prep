#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid, terminated_pid;
    int status;

    /*Create a child process*/
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        /*This code runs in the child process*/
        printf("Child process is running\n");
        sleep(2); /*Simulate some work in the child process*/
        exit(42); /* Terminate the child process with exit status 42*/
    } else {
        /*This code runs in the parent process*/
        printf("Parent process is waiting for child to terminate\n");
        
        /*Use the wait system call to wait for any child process to terminate*/
        terminated_pid = wait(&status);

        if (terminated_pid == -1) {
            perror("wait");
            exit(1);
        }

        if (WIFEXITED(status)) {
            printf("Child process with PID %d terminated with status %d\n", terminated_pid, WEXITSTATUS(status));
        } else {
            printf("Child process with PID %d terminated abnormally\n", terminated_pid);
        }

        /* Parent process continues here*/
    }

    return 0;
}
