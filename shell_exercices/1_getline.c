#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    /*check for lineptr, n , stream */
    /*check if the line ptr is null and n is 0 allocate with realoc*/

    /*start reading character by character an check if the we reached*/ 
    /*the end of the buffer*/ 
    ssize_t byteRead = 0;
    int c;
    char *new_buffer;
    int new_size;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return (-1);

    if(*lineptr == NULL || *n == 0)
    {
        *n = 128;
        new_buffer = (char *)realloc(*lineptr, *n);
        if (new_buffer == NULL)
            return (-1);
        *lineptr = new_buffer;
    }

    /*start reading*/ 
    while ((c = fgetc(stream) != EOF))
    {
        if (byteRead >= (ssize_t)*n)
        {
            /* have a new size*/
            new_size = *n * 2;
            new_buffer = (char *)realloc(*lineptr, new_size);
            if (new_buffer == NULL)
                return(-1);
            *n = new_size;
            *lineptr = new_buffer;
        }
        (*lineptr)[byteRead++] = c;

        if (c == '\n')
            break;
    }
    
    if (byteRead == 0)
        return (-1);

    (*lineptr)[byteRead] = '\0';
    return (byteRead);
}
int main(void)
{
    size_t n = 0;
    char *cmd = NULL;
    printf("$ ");
    if (getline(&cmd, &n, stdin) == -1)
    {
        printf("can't read the line \n");
        return (1);
    }
    printf("line typed: %s", cmd);
    return (0);
}