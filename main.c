#include "main.h"





int main(int argc, char **argv)
{


    char *line = NULL ;
    int status = 0;
    (void) argc;
    (void) argv;

    while (1)
    {
        line = Read_lien();
        if (line == NULL)
        {
            if (isatty(1))
                write(1, "$ ", 2);
            return (status);
        }
        free(line);
    }
    

   
    return (0);
}