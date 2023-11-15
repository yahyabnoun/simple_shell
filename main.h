#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



char *Read_lien(void);
void executingCommand(char **arr,int status);
/*
void HandleThePATH(char *name);
void HandleTheCommand(char **argv);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

*/





#endif
