#include "main.h"

char **split_str(char *cmd, const char *delim)
{
    int size = 0;
    char *token = NULL;
    char **arry_str = NULL;
    int i;
    char *cmd_copy = strdup(cmd);
    /*Count the number of strings*/
    token = strtok(cmd, delim);
    while(token != NULL)
    {
        size++;
        token = strtok(NULL, delim);
    }
    /*malloc the array of strings*/
    arry_str = (char **)malloc(sizeof(char *) * (size + 1));
    /*save each string inside of the string array*/
    i = 0;
    token = strtok(cmd_copy, delim);
    while(i < size)
    {
        arry_str[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    /*delimit the last spot with NULL*/
    arry_str[i] = NULL;
    return (arry_str);
}

    int main(void)
   {
    char str[] = "Hello;world it,is;great";
    char **array_str = NULL;
    const char *delim = ";, ";
    int i;
    
    array_str = split_str(str, delim);
    for(i = 0; array_str[i] != NULL; i++)
    {
        printf("[%d] %s\n", i, array_str[i]);
    }

    return (0);
   }