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

	parsed = shecktar_strtok(input, delim);
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;

	parsed = shecktar_strtok(NULL, delim);
	}

	command[index] = NULL;
	/* if command is "exit" */
	if (sj_strcmp(command[0], "exit") == 0)
	{
		hndl_exit(command);
	}

	return (command);
}
