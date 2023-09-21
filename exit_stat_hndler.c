#include "shell.h"
/**
* hndl_exit - function handles exit status
* @command: status of input to handle
* Return: void
*/
void hndl_exit(char **command)
{
	if (command[1] != NULL)
	{
		char *endptr;
		long status = sj_strtol(command[1], &endptr, 10);

		if (*endptr != '\0')
		{
			shecktar_write("Invalid integer argument for exit status\n");
			exit(EXITT_FAILURE);
		}
		exit((int)status);

	}
	else
	{
		exit(EXIT_SUCCESS);
	}

}

/**
* my_strlen - function is a custom strlen
* @str: string passed
* Return: always 0 success
*/
int my_strlen(const char *str)
{
	int counter = 0;

	if (str == NULL)
		return (0);

	while (str[counter] != '\0')
	{
		counter++;
	}

	return (counter);
}

