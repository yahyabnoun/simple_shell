#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>




void execveCheck(char **arr,int state);
char *Read_lien(void);
void executingCommand(char **arr,int status);


#endif