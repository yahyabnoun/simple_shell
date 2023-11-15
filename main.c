#include "main.h"





int main(int argc, char **argv)
{


    char *line = NULL ;
    int status = 0;
    (void)argc;
    (void)argv;

    while (1)
    {
        line = Read_lien();
        if (line == 0)
        {
            if (isatty(0))
                write(1, "$ ", 2);
            return (status);
        }
    }
    printf("%s",line);
    free(line);

   
    return (0);
}