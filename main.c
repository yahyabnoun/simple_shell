#include "main.h"

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * This function initializes variables, reads input lines, tokenizes them,
 * and executes commands in an infinite loop. It uses dynamic memory allocation
 * to store tokens and ensures proper handling of the main execution flow.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: Always returns 0 on successful execution.
 */

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
	/* end read line ------------------ */
	/* token */
	arr = (char **)malloc(sizeof(char *) * 1024);
	token = strtok(line, " \n\t");
	while (token)
	{
		arr[ind] = token;
		token = strtok(NULL, " \t\n");
		ind++;
	}
	arr[ind] = NULL;
	/* end token ------------------ */
	if (arr[0])
		executingCommand(arr, status);
	ind = 0;
	free(token);
	token = NULL;
	free(line);
	line = NULL;
	free(arr);
	}
	return (0);
}
