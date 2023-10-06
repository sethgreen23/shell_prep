#include "main.h"

int main(void)
{
    extern char **environ;
    char *token = NULL;
    int i;
    char **environ_copy = NULL;

    /*Calculate the length of environ*/
    i = 0;
    while(environ[i] != NULL)
        i++;
    printf("[size]  %d\n", i);
    environ_copy = (char **)malloc(sizeof(char *) * (i + 1));
    if (environ_copy == NULL)
    {
        printf("environ_copy cant be allocated\n");
        return (1);
    }
    /*Copy environ to environ_copy*/
    i = 0;
    while(environ[i] != NULL)
    {
        environ_copy[i] = strdup(environ[i]);
        i++;
    }
    /*Extract the path from the environ_copy*/
    i = 0;
    while(environ_copy[i] != NULL)
    {   
        
        token = strtok(environ_copy[i],"=");
        if (!strcmp(token, "PATH"))
            break;
        i++;
    }
    token = strtok(NULL, "\0");
    /*We have the PATH inside the token*/
    printf("\n\n\n%s\n", token);

    return(0);
}