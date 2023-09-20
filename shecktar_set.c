#include "shell.h"
/**
* sj_setenv - function creates or modifies an existing env var
* @args: command arguments
* Return: void
*/
void sj_setenv(char **args)
{
		if (args[1] == NULL)
		{
			sj_fprintf(stderr, "Error: variable name missing for setenv command. \n");
				return;
		}
		if (args[2] == NULL)
		{
			sj_fprintf(stderr, "Error, Variable value missing for setenv command. \n");
				return;

		}

		if (setenv(args[1], args[2], 1) == -1)
		{
			sj_fprintf(stderr, "Error: setenv failed. \n");
		}
}

/**
* sj_unsetenv - function removes an environment variable
* @args: command arguments
* Return: void
*/
void sj_unsetenv(char **args)
{
		if (args[1] == NULL)
		{
			sj_fprintf(stderr, "Error: Variable name missing for unsetenv command. \n");
			return;
		}

		if (unsetenv(args[1]) == -1)
		{
			sj_fprintf(stderr, "Error: unsetenv failed. \n");
		}
}
