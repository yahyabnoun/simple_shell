#include "main.h"

int main(int argc, char **argv)
{
    char *line = NULL;
    int status = 0;
    char *token = NULL;
    char **arr = NULL;
    int ind = 0;
    (void)argc;
    (void)argv;

    while (1)
    {
        /* read line */
        line = Read_lien();
        if (line == NULL)
        {
            free(line);
            return (status);
        }
        /* end read line ------------------*/
        /* token*/
        arr = (char **)malloc(sizeof(char *) * 1024);

        token = strtok(line, " \n\t");
        
        while (token)
        {
            arr[ind] = token;
            token = strtok(NULL, " \t\n");
            ind++;
        }

        arr[ind] = NULL;
        /* end token ------------------*/
        /* executing Command */
        if (arr[0])
            executingCommand(arr, status);
        /* end executing Command ------------------*/






/* HandleThePATH("PATH");
*/
     







        ind = 0;
        free(token);
        token = NULL;
        free(line);
        line = NULL;
        free(arr);
    }
    return (0);
}
