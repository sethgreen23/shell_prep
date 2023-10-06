#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *programPath = "/bin/ls"; /* Path to the program you want to execute*/
    char *argv[] = {programPath, "-la", NULL}; /*Array of arguments for the new program*/ 
    char *envp[] = { NULL}; /*Array of environment variables (optional)*/ 

    /*Use execve to replace the current process with a new program*/ 
    if (execve(programPath, argv, envp) == -1) {
        perror("execve"); /*Print an error message if execve fails*/ 
        return 1;
    }

    /*The code here will not be executed because execve replaces the process image*/
    printf("This will not be printed\n");

    return 0;
}
