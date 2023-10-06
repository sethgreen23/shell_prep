#include "main.h"

int main(int ac, char **av, char **envp)
{
    int status;
    char **env;
    (void) envp;
    (void) ac;
    (void) av;
    (void) env;
    /*
    for (env = environ; env[i] != NULL; i++)
    {
        printf("%s\n", env[i]);
    }
    return (0);
    */
    /*having a loop that make the shell work*/
    while(1)
    {
        status = _getline();
        if (status == 1)
        {
            return (1);
        }
    }
    return(0);
}