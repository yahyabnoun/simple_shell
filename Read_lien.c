#include "main.h"



char *Read_lien(void)
{

        char *line = NULL ;
        size_t len = 0;
        size_t n;

        write(1, "$ ", 2);
        n = getline(&line, &len, stdin);
        if (n==1)
        {
            free(line);
            return NULL ;
        }
        return NULL;
}