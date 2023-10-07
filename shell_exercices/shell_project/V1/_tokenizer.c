#include "main.h"

void _tokenizer(char *cmd)
{
    /**
        need to copy the cmd
        need to go throw string to count the strings
        malloc the new array of strings
        if the first element contain / means it is absolute path
        if not i need to search in the environ for the path variable
    */
    char *cmd_copy = NULL;
    char *token = NULL;
    int size = 0, i;
    const char *delim = " \n";
    char **argv = NULL;
    char *pathname = NULL;

    /*copy the cmd*/ 
    cmd_copy = strdup(cmd);
    (void)cmd_copy;
    /*cunt the number of strings*/ 
    token = strtok(cmd, delim);
    while(token != NULL)
    {
        size++;
        token = strtok(NULL, delim);
    }
    /*Fill the argv with strings*/
    argv = (char **)malloc(sizeof(char *) * (size + 1));
    token = strtok(cmd_copy, delim);
    i = 0;
    while(token != NULL && i < size)
    {
        argv[i++] = strdup(token);
        token = strtok(NULL, delim);
    }
    /*Put the '\0' at the end of the array*/
    argv[i] = NULL;
    /**
    for(i = 0; i < size; i++){
        printf("[%d] %s\n", i, argv[i]);
    }
    
        now i have the argv table
    */
    /*We evaluate the argv[0] and return the absolute value from it */
    
    pathname = _evaluate(argv[0]);
    if(pathname == NULL)
    {
        perror("file is not recognized\n");
        _getline();
    }
    else{
    argv[0] = pathname;
    _execve(pathname, argv);
    _getline();
    }
}