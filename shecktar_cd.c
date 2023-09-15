#include "shell.h"
/**
* hndl_cd - function chanages user cwd
* @args: command args
* Return: 1 if succesful and -1 on error
*/
int hndl_cd(char **args)
{
	if (args[1] == NULL)
	{
		char *home;

		home = getenv("HOME");

		if (home == NULL)
		{
			shecktar_write("Cannot get home directory\n");
			return (-1);
		}
		if (chdir(home) != 0)
		{
			perror("shecktar");
			return (-1);
		}
	}
	else
		{
			if (chdir(args[1]) != 0)
			{
				perror("shecktar");
				return (-1);
			}
		}
		return (1);
}
