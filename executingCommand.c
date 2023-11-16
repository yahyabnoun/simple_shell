#include "main.h"

/**
 * executingCommand - Executes a command in a new process.
 * @arr: Array of arguments representing the command and its parameters.
 * @status: Status variable to store the child process status.
 *
 * This function forks a new process using fork(). In the child process, it
 * executes the command specified in the 'arr' array using execve(). The
 * parent process waits for the child process to complete using wait().
 *
 * @arr: Array of arguments representing the command and its parameters.
 * @status: Status variable to store the child process status.
 */

void executingCommand(char **arr, int status)
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
