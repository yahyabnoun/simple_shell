#include "main.h"

/**
 * Read_lien - Reads a line of input from the standard input.
 *
 * This function reads a line of input from the standard input, displaying a
 * prompt if the input is from a terminal. It uses the getline function to
 * dynamically allocate memory for the input buffer and handles potential
 * errors during the reading process.
 *
 * Return: A pointer to the dynamically allocated buffer containing the input
 * line. Returns NULL in case of an error or if the input line is empty.
 */

char *Read_lien(void)
{

	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	if (isatty(STDIN_FILENO))
	{
	write(1, "$ ", 2);
	}

	characters = getline(&buffer, &bufsize, stdin);

	if (characters == -1 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
