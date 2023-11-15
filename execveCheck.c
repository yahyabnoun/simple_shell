#include "main.h"



void execveCheck(char **arr)
{
        pid_t p;

        p = fork();

        if (p == 0)
        {
            if (execve(arr[0], arr, NULL) == -1)
                perror("execve");
            // exit(0);
        }
        // else
        //     wait(&status);
}