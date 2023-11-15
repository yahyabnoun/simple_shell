#include "main.h"



void executingCommand(char **arr,int status)
{

        pid_t p;
        p = fork();

        if (p == 0)
        {
            if (execve(arr[0], arr, NULL) == -1)
                perror("execve");
            
        }
        else
            wait(&status);
}