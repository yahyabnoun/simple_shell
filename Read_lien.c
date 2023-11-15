#include "main.h"



char *Read_lien(void)
{

        char *buffer = NULL;
        size_t bufsize = 0;
        ssize_t characters;

        if (isatty(STDIN_FILENO))
        {
            write(1, "$ ", 2);
        }
        
        characters = getline(&buffer, &bufsize, stdin);
        
        if (characters == -1 || !buffer)
        {
            free(buffer);
            return (NULL);
        }
    /*

     */    
        return (buffer);
}