#include "main.h"


char *_strtok(char *str, const char *delim)
{
    
    /*declare static variable that will hold the token*/ 
    static char *lastToken = NULL;
    char *tokenStart = NULL, *tokenEnd = NULL;
    /* if str != NULL this is when 
    we first start to tokenize the string*/
    if (str != NULL)
    {
        lastToken = str;
    }
    else if (lastToken == NULL)
    {
        return (NULL);
    }
    /*search for the start of the token ignoring the delimeter
    at the beggining*/
    tokenStart = lastToken + strspn(lastToken, delim);
    /*if after some delimeter or not we find the end of the string
    we dont have a next token we return null*/
    if (*tokenStart == '\0')
    {
        lastToken = NULL;
        return(NULL);
    }
    /*we find the end of the string were we find a delimiter or not*/
    tokenEnd = tokenStart + strcspn(tokenStart, delim);
    /*if we didnt yet reached the end of the string
        we mark the end of end of the string by \0
        and we mark the next token
    */
    if (*tokenEnd != '\0')
    {
        *tokenEnd = '\0';
        lastToken = tokenEnd + 1;
    }
    else /*we reached the end of the string we dont have a next token*/
    {
        lastToken = NULL;
    }
    return (tokenStart);
}

