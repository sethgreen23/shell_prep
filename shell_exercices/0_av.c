#include "main.h"

int main (int ac , char **av)
{
    int i = 0; 

    (void) ac;
    if (av == NULL)
    {
        printf("No arguments are given!!\n");
        return (1);
    }
    for (; av[i] != NULL; i++)
    {
        printf("[%d] %s\n", i, av[i]);
    }
    return (0);
}