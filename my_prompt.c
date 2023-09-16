#include "shell.h"

/**
* display_prompt - function displays a promt in termial
* Return: void
*/
void display_prompt(void)
{
	shecktar_write("$ ");
}

/**
* hndl_builtins - Function handles builtin commands setenv and unset
* @args: command arguments
* Return: integer showing if a command was executed or not
*/
int hndl_builtins(char **args)
{
		if (args[0] == NULL)
		{
			return (0);
		}

		if (sj_strcmp(args[0], "setenv") == 0)
		{
			sj_setenv(args);
			return (1);
		}

		if (sj_strcmp(args[0], "unsetenv") == 0)
		{
			sj_unsetenv(args);
			return (1);
		}

		if (sj_strcmp(args[0], "cd") == 0)
		{
			hndl_cd(args);
			return (1);
		}

		return (0);
}
