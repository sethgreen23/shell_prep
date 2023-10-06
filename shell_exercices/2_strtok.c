#include "main.h"


char *_strtok(char *str, const char *delim)
{
    /*
        have a static variable that track the lasttoken
        if the str != NULL (i didnt start reading the token)
            lasttoken the str(this is on the begining)
        else if lasttoken equel to NULL it mean im at the end
            return null
        need to get the start of the token ignoring the delimiters
        if the start is the end of the string
            lasttoken take null and return lasttoken
        need to calculate end of token 
            count the number of character till i found a delimeter
        if last element is not the end of the string
            lastelement  = '\0'
            lasttoken = latelemnt +1
        else 
            lasttoken = NULL
        return token start
    */
    
    static char *lastToken = NULL;
    char *tokenStart = NULL, *tokenEnd = NULL;

    if (str != NULL)
    {
        lastToken = str;
    }
    else if (lastToken == NULL)
    {
        return (NULL);
    }

    tokenStart = lastToken + strspn(lastToken, delim);
    if (*tokenStart == '\0')
    {
        lastToken = NULL;
        return(NULL);
    }
    tokenEnd = tokenStart + strcspn(tokenStart, delim);
    if (*tokenEnd != '\0')
    {
        *tokenEnd = '\0';
        lastToken = tokenEnd + 1;
    }
    else
    {
        lastToken = NULL;
    }
    return (tokenStart);
}

