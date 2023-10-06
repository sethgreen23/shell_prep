#include "main.h"

char *_evaluate(char *cmd)
{
    char **environ_copy = NULL;
    char *token = NULL;
    int i;
    char *path = NULL;
    char *test_path = NULL;
    struct stat sb;
    int status;


    
    /*Calculate the length of environ*/
    i = 0;
    while(environ[i] != NULL)
        i++;
    environ_copy = (char **)malloc(sizeof(char *) * (i + 1));
    if (environ_copy == NULL)
    {
        printf("environ_copy can't be allocated\n");
        return (NULL);
    }
    /*Copy environ to environ_copy*/
    i = 0;
    while(environ[i] != NULL)
    {
        environ_copy[i] = strdup(environ[i]);
        i++;
    }
    environ_copy[i] = NULL;
    /*Extract the path from the environ_copy*/
    i = 0;
    while(environ_copy[i] != NULL)
    {
        token = strtok(environ_copy[i], "=");
        if(!strcmp(token, "PATH"))
            break;
        i++;
    }
    /*We got the path*/
    path = strtok(NULL, "\0");
    /*printf("\n\n\n[PATH] %s\n", path);*/
    
    /*Tokenize the path and get the right path*/
    if (cmd[0] != '/')
    {
        token = strtok(path, ":");
        while(token != NULL)
        {
            test_path = malloc(sizeof(char) * (strlen(token) + strlen(cmd) + 2));
            if (test_path == NULL)
                return(NULL);
            test_path = strcat(test_path, token);
            test_path = strcat(test_path, "/") ;
            test_path = strcat(test_path, cmd);
            if((status = stat(test_path, &sb)) == 0)
                break;
            else
            {
                free(test_path);
                token = strtok(NULL, ":");
            }
        }
        if (status == 0)
         {
            cmd = strdup(test_path);
         }
         else
            return (NULL);
    }
    
    return(cmd);
}