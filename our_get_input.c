#include "shell.h"
/**
* sj_get_input - function get inputs from user
* @input: input from users
* Return: user input
*/
char **sj_get_input(char *input)
{
		char **command;
		char *delim;
		char *parsed;
		int index;

		if (input == NULL)
	{
		perror("Error: Null input string");
		exit(EXIT_FAILURE);
	}

	command = malloc(8 * sizeof(char *));

	if (command == NULL)
	{
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	delim = " ";
	index = 0;

	parsed = strtok(input, delim);
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;

	parsed = strtok(NULL, delim);
	}

	command[index] = NULL;
	return (command);
}
