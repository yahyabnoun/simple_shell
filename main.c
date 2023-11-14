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

int main(int argc, char **argv, char **env)
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    char *token;
    pid_t p;
    int status, ind = 0;
    char **arr = NULL;
    (void)argc;
    (void)argv;

    buffer = (char *)malloc(bufsize * sizeof(char));

    if (buffer == NULL)
    {
        perror("Unable to allocate buffer\n");
        exit(127);
    }

    while (1)
    {

        characters = getline(&buffer, &bufsize, stdin);
        if (isatty(1))
        {
            write(1, "$ ", 2);
            // exit(0);
        }

        arr = malloc(sizeof(characters) * sizeof(char) + 1);
        token = strtok(buffer, " \n\t");
        if (token == NULL)
            exit(0);
        // printf("You typed: '%ld' \n", sizeof(characters));

        while (token)
        {
            arr[ind] = token;
            token = strtok(NULL, " \t\n");
            ind++;
        }

        arr[ind] = NULL;
        p = fork();

        if (p == 0)
        {
            if (execve(arr[0], arr, NULL) == -1)
                perror("execve");
            exit(0);
        }
        else
            wait(&status);

            
        ind = 0;
        free(arr);
        free(token);
        buffer = NULL;
        // printf("You typed: '%s' \n", execve(argv[0], argv, NULL));
    }

    return (0);
}