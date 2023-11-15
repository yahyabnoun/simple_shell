// #include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - initialize the variables of the program
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: number of values received from the command line
 * Return: zero on succes.
 */



void execveCheck(char **arr,int status)
{
        pid_t p;
        p = fork();

        if (p == 0)
        {
            if (execve(arr[0], arr, NULL) == -1)
                perror("execve");
            exit(0);
        }
        else
            wait(&status);

}


void free2dArray(char **x, int rows)
{
  for (int i = 0; i < rows; i++)
    free(x[i]);
    free(x);
}


int main(int argc, char **argv, char **env)
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    char *token;
    int status;
    int ind = 0;
    char **arr;
    // extern char **environ ;
    (void)argc;
    (void)argv;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL)
    {
        free(buffer);
        perror("Unable to allocate buffer\n");
        exit(127);
    }

    while (1)
    {
        if (isatty(0))
        {
            write(1, "$ ", 2);
        }
        characters = getline(&buffer, &bufsize, stdin);


        arr = (char **)malloc(sizeof(char *) * bufsize);
        token = strtok(buffer, " \n\t");
        if (!characters || !token)
        {
            free(buffer);
            free(token);
            buffer = NULL;
            exit(0);
        }


        while (token)
        {
            arr[ind] = token;
            token = strtok(NULL, " \t\n");
            ind++;
        }
        free(token);
        free(buffer);
        buffer = NULL;




        if (arr[0])
        {
            execveCheck(arr,status);
        }
        
        

        // free2dArray(arr,  2);

        ind = 0;
        // printf("You typed: '%s' \n", execve(argv[0], argv, NULL));
    }

    return (0);
}