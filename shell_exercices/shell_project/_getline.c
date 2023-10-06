#include "main.h"

int _getline()
{
    char *cmd = NULL;
    size_t n = 0;
    printf("$ ");
    if (getline(&cmd, &n, stdin) == -1)
    {
        perror("Can't read from the Standard Input");
        free(cmd);
        return (1);
    }
    /*printf("the string entered %s", cmd);*/
    /*free(cmd);*/
    _tokenizer(cmd);
    free(cmd);
    return (0);
}