#include "main.h"


int main(int ac, char **av)
{
    size_t n = 0;
    char *cmd = NULL;

    (void)ac;
    (void)av;
    printf("$ ");
    if(getline(&cmd, &n, stdin) == -1)
    {
        free(cmd);
        return (1);
    }
    printf("What i typed: %s\n", cmd);
    free(cmd);
    return(0);
}