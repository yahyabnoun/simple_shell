#include "main.h"


void HandleThePATH(char *name)
{
    extern char **environ ;
    int i = 0;
    char *key;

    while (environ[i])
    {
        key = strtok(environ[i], "=");
        if (_strcmp(key,name)==0)
        {
            key = strtok(NULL, "\n");
            printf("%s\n",key);
        }
        
        
        i++;
    } 
    
}
