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
		if (args == NULL || args[0] == NULL)
		{
			return (0);
		}
		if (sj_strcmp(args[0], "setenv") == 0 && args[1] != NULL)
		{
			sj_setenv(args);
			return (1);
		}
		if (sj_strcmp(args[0], "unsetenv") == 0 && args[1] != NULL)
		{
			sj_unsetenv(args);
			return (1);
		}

		if (sj_strcmp(args[0], "cd") == 0)
		{
			hndl_cd(args);
			return (1);
		}
		if (sj_strcmp(args[0], "clear") == 0)
		{
			const char clear_terminal[] = "\033[1;1H\033[2J";

			write(STDOUT_FILENO, clear_terminal, sizeof(clear_terminal));
			return (1);
		}
		return (0);
}
